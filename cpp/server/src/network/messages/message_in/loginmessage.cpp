#include "network/messages/message_in/loginmessage.h"

#include "logic/events/event.h"

namespace slice_hack {
namespace network {
namespace messages {
namespace message_in {

LoginMessage::LoginMessage() : MessageInterpreter(1) {}

LoginMessage::~LoginMessage() {}

events::Event *LoginMessage::GetEvent(Buffer *buffer) const {
  return NULL;
}

void LoginMessage::CleanEvent(events::Event *event) const {
  if (event) {
    delete event;
  }
}

}  // namespace message_in
}  // namespace messages
}  // namespace network
}  // namespace slice_hack
