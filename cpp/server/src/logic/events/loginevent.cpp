#include "logic/events/loginevent.h"

#include "logic/events/eventvisitorinterface.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace events {

LoginEvent::LoginEvent(const std::string &name)
    : Event(true, NULL),
      name_(name) {}

LoginEvent::~LoginEvent() {}

const std::string &LoginEvent::name() const {
  return name_;
}

void LoginEvent::Accept(EventVisitorInterface *event_visitor) {
  event_visitor->Visit(this);
}

}  // namespace events 
}  // namespace slice_hack
