#include "logic/events/chatevent.h"

#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {
namespace events {

ChatEvent::~ChatEvent() {}

ChatEvent::ChatEvent() {}

void ChatEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
