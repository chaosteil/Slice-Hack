#include "logic/events/chatevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

ChatEvent::ChatEvent(game_map::entities::Entity *origin)
    : Event(true, origin) {}

ChatEvent::~ChatEvent() {}

void ChatEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
