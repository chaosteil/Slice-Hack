#include "network/server.h"
#include "network/clientmanagerinterface.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <boost/foreach.hpp>
#include "network/client.h"
#include "network/messages/message_out/loginmessage.h"

namespace slice_hack {
namespace network {

Server::Server()
    : EventHandlerInterface(),
      listen_fd_(0),
      event_loop_(NULL),
      client_manager_(NULL) {}

Server::~Server() {
  StopListen();
  DisconnectAllClients();
}

bool Server::StartListen(int port, int max_connections,
                         ClientManagerInterface *client_manager,
                         EventLoop *event_loop) {
  addrinfo hints, *servinfo, *p;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  char real_port[10]; sprintf(real_port, "%u", port); 
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

  freeaddrinfo(servinfo);

  if (p == NULL) {
    return false;
  }

  if (listen(sockfd, 10) == -1) {
    return false;
  }

  listen_fd_ = sockfd;

  event_loop->AddFileEvent(listen_fd_, this);
  event_loop_ = event_loop;

  client_manager_ = client_manager;

  return true;
}

void Server::StopListen() {
  event_loop_->RemoveFileEvent(listen_fd_);
  close(listen_fd_);
}

void Server::HandleEvent(int fd, FileEventType event) {
  std::cout << "[" << fd << "," << (int)event << "]" << std::endl;

  if (fd == listen_fd_) {
    AcceptClient();
  } else {
    Client *client = clients_[fd];

    if (client == NULL) {
      return;
    }

    char buf[256] = "";
    int received = recv(fd, buf, sizeof(buf)-1, 0);

    if (received <= 0) {
      Disconnect(client);
    } else {
      if (client_manager_) {
        client->AddBuffer(buf, received);
        if (client_manager_->HandleBuffer(client) ==
            ClientManagerInterface::kInvalid) {
          Disconnect(client);
        }
      }
    } 
  }
}

void Server::Disconnect(Client *client) {
  int fd = client->fd();
  std::cout << fd << " disconnected" << std::endl;

  if (client_manager_) {
    client_manager_->RemoveClient(client);
  }

  close(fd);
  event_loop_->RemoveFileEvent(fd);

  clients_.erase(fd);

  delete client;
}

void Server::DisconnectAllClients() {
  while (clients_.size() != 0) {
    Disconnect(clients_.begin()->second);
  }

  clients_.clear();
}

void Server::AcceptClient() {
  sockaddr_storage address;
  socklen_t address_size = sizeof(address);

  int client_fd = accept(listen_fd_, (sockaddr *)&address, &address_size);

  Client *client = new Client(client_fd);

  clients_[client_fd] = client;
  event_loop_->AddFileEvent(client_fd, this);

  std::cout << "Accepted client on " << client_fd << ::std::endl;

  if (client_manager_) {
    client_manager_->AddClient(client);
  }

  client->SendMessage(
    messages::message_out::LoginMessage(
      messages::message_out::LoginMessage::kOk, "derp"));
}

}  // namespace network
}  // namespace slice_hack
