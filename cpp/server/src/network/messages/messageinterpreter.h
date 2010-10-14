#ifndef SLICE_HACK_NETWORK_MESSAGES_MESSAGEINTERPRETER_H_
#define SLICE_HACK_NETWORK_MESSAGES_MESSAGEINTERPRETER_H_

#include <string>

#include "logic/events/eventmanagerinterface.h"
#include "network/clientmanagerinterface.h"

namespace slice_hack {

namespace events {
class Event;
}  // namespace events

namespace game_map {
namespace entities {
class Entity;
}  // namespace entities
}  // namespace game_map

namespace network {
namespace messages {

class MessageInterpreter : public events::EventManagerInterface {
 public:
  struct Buffer {
    const char *buf;
    int length;
    int pos;
  };

  virtual ~MessageInterpreter();

  int id() const;
  virtual events::Event *GetEvent(Buffer *buffer,
                                  game_map::entities::Entity *origin) const = 0;
  virtual void CleanEvent(events::Event *event) const = 0;

  static bool DrainString(std::string *text, Buffer *buffer);
  static bool DrainInt8(int *number, Buffer *buffer);
  static bool DrainInt16(int *number, Buffer *buffer);
  static bool DrainInt32(int *number, Buffer *buffer);

 protected:
  MessageInterpreter(int id);

 private:
  int id_;
};

}  // namespace messages
}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_MESSAGES_MESSAGEINTERPRETER_H_
