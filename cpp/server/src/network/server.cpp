#include "network/server.h"

#include "network/client.h"

namespace slice_hack {
namespace network {

Server::Server() : EventHandlerInterface(), listen_fd_(0) {}

Server::~Server() {}

bool Server::StartListen(int port, int max_connections,
                         EventLoop *event_loop) {}

void Server::StopListen() {}

void Server::HandleEvent(int fd, FileEventType event) {}

}  // namespace network
}  // namespace slice_hack
