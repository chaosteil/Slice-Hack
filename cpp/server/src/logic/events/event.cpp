#include "logic/events/event.h"

namespace slice_hack {
namespace events {

Event::~Event() {}

bool Event::global() const {
  return global_;
}

game_map::entities::Entity *Event::origin() const {
  return origin_;
}

Event::Event(bool global, game_map::entities::Entity *origin)
    : global_(global), origin_(origin) {}

}  // namespace events 
}  // namespace slice_hack

