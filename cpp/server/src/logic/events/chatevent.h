#ifndef SLICE_HACK_LOGIC_EVENTS_CHATEVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_CHATEVENT_H_

#include "logic/events/event.h"

namespace slice_hack {
namespace events {

class ChatEvent : public Event {
 public:
  ChatEvent(game_map::entities::Entity *origin);
  virtual ~ChatEvent();

  virtual void Accept(EventVisitorInterface *event_visitor);
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_CHATEVENT_H_
