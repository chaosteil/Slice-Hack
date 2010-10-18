#include "network/messages/message_out/loginmessage.h"

namespace slice_hack {
namespace network {
namespace messages {
namespace message_out {

LoginMessage::LoginMessage(LoginError error, const std::string &name)
    : SendMessage(1) {
  AddInt8((int)error);
  AddString(name);
}

LoginMessage::~LoginMessage() {}

}  // namespace message_out
}  // namespace messages
}  // namespace network
}  // namespace slice_hack
