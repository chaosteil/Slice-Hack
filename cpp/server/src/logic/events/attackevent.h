#ifndef SLICE_HACK_LOGIC_EVENTS_ATTACKEVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_ATTACKEVENT_H_

#include "logic/events/event.h"

namespace slice_hack {
namespace events {

class AttackEvent : public Event {
 public:
  AttackEvent();
  virtual ~AttackEvent();

  virtual void Accept(EventVisitorInterface *event_visitor);
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_ATTACKEVENT_H_
