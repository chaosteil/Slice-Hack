#include "logic/events/enterevent.h"

#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {
namespace events {

EnterEvent::~EnterEvent() {}

EnterEvent::EnterEvent() : Event(true) {}

void EnterEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
