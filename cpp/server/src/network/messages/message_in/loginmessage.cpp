#include "network/messages/message_in/loginmessage.h"

#include "logic/events/event.h"
#include "logic/events/loginevent.h"

namespace slice_hack {
namespace network {
namespace messages {
namespace message_in {

LoginMessage::LoginMessage() : MessageInterpreter(1) {}

LoginMessage::~LoginMessage() {}

events::Event *LoginMessage::GetEvent(Buffer *buffer,
    game_map::entities::Entity *origin) const {
  std::string user_name;

  if (!DrainString(&user_name, buffer)) {
    return NULL;
  }

  return new events::LoginEvent(user_name);
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
