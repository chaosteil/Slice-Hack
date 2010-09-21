#ifndef SLICE_HACK_LOGIC_EVENTS_ITEMUSEEVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_ITEMUSEEVENT_H_

#include "logic/events/event.h"

namespace slice_hack {
namespace events {

class ItemUseEvent : public Event {
 public:
  ItemUseEvent();
  virtual ~ItemUseEvent();

  virtual void Accept(EventVisitorInterface *event_visitor);
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_ITEMUSEEVENT_H_
