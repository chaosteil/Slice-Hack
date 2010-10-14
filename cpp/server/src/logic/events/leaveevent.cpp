#include "logic/events/leaveevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

LeaveEvent::~LeaveEvent() {}

LeaveEvent::LeaveEvent() : Event(false, NULL) {}

void LeaveEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack

