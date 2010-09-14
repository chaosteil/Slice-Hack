#include "logic/game_map/entities/monster.h"

#include <iostream>

namespace slice_hack {
namespace game_map {
namespace entities {

Monster::Monster(const boost::uuids::uuid &id, const std::string &name,
                 const Health &health)
    : Entity(id, name, health),
      tick_(0) {}

Monster::~Monster() {}

void Monster::Run() {
  tick_++;

  if (tick_ == 5) {
    tick_ = 0;
  }
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
