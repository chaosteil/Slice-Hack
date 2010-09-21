#include "network/server.h"

#include "logic/eventloop.h"

namespace slice_hack {
namespace network {

Server::Server() : EventHandlerInterface() {}
Server::~Server() {}

bool Server::StartListen(int port, int max_connections,
                         EventLoop *event_loop) {}

void Server::StopListen() {}

void Server::HandleEvent(int fd, FileEventType event) {}

}  // namespace network
}  // namespace slice_hack
