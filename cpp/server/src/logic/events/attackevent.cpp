#include "logic/events/attackevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

AttackEvent::AttackEvent() : Event(false, NULL) {}

AttackEvent::~AttackEvent() {}

void AttackEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
