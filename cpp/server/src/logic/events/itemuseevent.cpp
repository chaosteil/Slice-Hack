#include "logic/events/itemuseevent.h"

#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {
namespace events {

ItemUseEvent::~ItemUseEvent() {}

ItemUseEvent::ItemUseEvent() : Event(false) {}

void ItemUseEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack

