#ifndef SLICE_HACK_LOGIC_EVENTS_ENTEREVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_ENTEREVENT_H_

#include "logic/events/event.h"

namespace slice_hack {
namespace events {

class EnterEvent : public Event {
 public:
  EnterEvent(game_map::entities::Entity *origin);
  virtual ~EnterEvent();

  virtual void Accept(EventVisitorInterface *event_visitor);
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_ENTEREVENT_H_
