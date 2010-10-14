#include "logic/events/chatevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

ChatEvent::ChatEvent() : Event(true, NULL) {}

ChatEvent::~ChatEvent() {}

void ChatEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
