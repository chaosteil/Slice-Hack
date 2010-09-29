#include "logic/events/event.h"

namespace slice_hack {
namespace events {

Event::~Event() {}

bool Event::global() const {
  return global_;
}

Event::Event(bool global) : global_(global) {}

}  // namespace events 
}  // namespace slice_hack

