#include "network/server.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "network/client.h"

namespace slice_hack {
namespace network {

Server::Server() : EventHandlerInterface(), listen_fd_(0) {}

Server::~Server() {}

bool Server::StartListen(int port, int max_connections,
                         EventLoop *event_loop) {
  addrinfo hints, *servinfo, *p;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  char real_port[10];
  sprintf(real_port, "%u", port);

  getaddrinfo(NULL, real_port, &hints, &servinfo);
  
  int sockfd;
  int yes = 1;
  for (p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
         p->ai_protocol)) == -1) {
      continue;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
      continue;
    }

    if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      continue;
    }

    break;
  }

  if (p == NULL) {
    return false;
  }

  if (listen(sockfd, 10) == -1) {
    return false;
  }

  listen_fd_ = sockfd;

  event_loop->AddFileEvent(listen_fd_, this);
  return true;
}

void Server::StopListen() {}

void Server::HandleEvent(int fd, FileEventType event) {
  if (fd == listen_fd_) {
    // TODO(Chaosteil): Do server stuff (Accept)
  } else {
    Client *client = clients_[fd];

    if (client == NULL) {
      return;
    }
  }
}

void Server::Disconnect(Client *client) {
}

}  // namespace network
}  // namespace slice_hack
