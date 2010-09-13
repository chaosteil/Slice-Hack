#include "logic/game_map/entities/monster.h"

#include <iostream>

namespace slice_hack {
namespace game_map {
namespace entities {

Monster::Monster(const boost::uuids::uuid &id, const std::string &name,
                 const Health &health)
    : Entity(id, name, health) {}

Monster::~Monster() {}

void Monster::Run() {
  tick_++;

  if (tick_ == 10) {
    tick_ = 0;

    std::cout << "Imma monsta!" << std::endl;
  }
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
