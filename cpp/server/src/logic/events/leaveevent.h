#ifndef SLICE_HACK_LOGIC_EVENTS_LEAVEEVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_LEAVEEVENT_H_

#include "logic/events/event.h"

namespace slice_hack {
namespace events {

class LeaveEvent : public Event {
 public:
  LeaveEvent();
  virtual ~LeaveEvent();

  virtual void Accept(EventVisitorInterface *event_visitor);
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_LEAVEEVENT_H_
