#include "network/server.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "network/client.h"

namespace slice_hack {
namespace network {

Server::Server()
    : EventHandlerInterface(),
      listen_fd_(0),
      event_loop_(NULL) {}

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
  event_loop_ = event_loop;

  return true;
}

void Server::StopListen() {}

void Server::HandleEvent(int fd, FileEventType event) {
  std::cout << "[" << fd << "," << (int)event << "]" << std::endl;
  if (fd == listen_fd_) {
    // TODO(Chaosteil): Do server stuff (Accept)
    AcceptClient();
  } else {
    Client *client = clients_[fd];

    if (client == NULL) {
      return;
    }

    char buf[256];
    int received = recv(fd, buf, sizeof(buf)-1, 0);

    if (received <= 0) {
      close (fd);
      event_loop_->RemoveFileEvent(fd);
    } else {
      buf[received+1] = '\0';

      std::cout << received << " " << buf << std::endl;
    } 
  }
}

void Server::Disconnect(Client *client) {}

void Server::AcceptClient() {
  sockaddr_storage address;
  socklen_t address_size = sizeof(address);

  int client_fd = accept(listen_fd_, (sockaddr *)&address, &address_size);

  Client *client = new Client(client_fd);

  clients_[client_fd] = client;
  event_loop_->AddFileEvent(client_fd, this);

  std::cout << "Accepted client on " << client_fd << ::std::endl;
}

}  // namespace network
}  // namespace slice_hack
