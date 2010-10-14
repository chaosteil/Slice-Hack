#include "logic/events/leaveevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

LeaveEvent::LeaveEvent(game_map::entities::Entity *origin)
    : Event(false, origin) {}

LeaveEvent::~LeaveEvent() {}

void LeaveEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack

