#include "logic/events/moveevent.h"

#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {
namespace events {

MoveEvent::~MoveEvent() {}

MoveEvent::MoveEvent() {}

void MoveEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
