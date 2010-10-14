#ifndef SLICE_HACK_NETWORK_MESSAGES_MESSAGE_IN_LOGINMESSAGE_H_
#define SLICE_HACK_NETWORK_MESSAGES_MESSAGE_IN_LOGINMESSAGE_H_

#include "network/messages/messageinterpreter.h"

namespace slice_hack {
namespace network {
namespace messages {
namespace message_in {

class LoginMessage : public MessageInterpreter {
 public:
  LoginMessage();
  virtual ~LoginMessage();

  virtual events::Event *GetEvent(Buffer *buffer,
                                   game_map::entities::Entity *origin) const;
  virtual void CleanEvent(events::Event *event) const;
};

}  // namespace message_in
}  // namespace messages
}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_MESSAGES_MESSAGE_IN_LOGINMESSAGE_H_
