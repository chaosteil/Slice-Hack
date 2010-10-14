#include "logic/events/itemuseevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

ItemUseEvent::ItemUseEvent(game_map::entities::Entity *origin)
    : Event(false, origin) {}

ItemUseEvent::~ItemUseEvent() {}

void ItemUseEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack

