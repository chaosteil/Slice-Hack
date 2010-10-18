#ifndef SLICE_HACK_NETWORK_MESSAGES_MESSAGE_OUT_LOGINMESSAGE_H_
#define SLICE_HACK_NETWORK_MESSAGES_MESSAGE_OUT_LOGINMESSAGE_H_

#include "network/messages/sendmessage.h"

namespace slice_hack {
namespace network {
namespace messages {
namespace message_out {

class LoginMessage : public SendMessage {
 public:
  enum LoginError {
    kOk = 0,
    kFail = 1
  };

  LoginMessage(LoginError error, const std::string &name);
  virtual ~LoginMessage();
};

}  // namespace message_out
}  // namespace messages
}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_MESSAGES_MESSAGE_OUT_LOGINMESSAGE_H_
