#include "network/client.h"

namespace slice_hack {
namespace network {

Client::Client(int fd) : fd_(fd) {}

Client::~Client() {}

int Client::fd() const {
  return fd_;
}

void Client::SendMessage(const messages::SendMessageInterface &send_message) {}

}  // namespace network
}  // namespace slice_hack
