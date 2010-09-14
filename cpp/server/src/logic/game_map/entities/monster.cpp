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

  if (tick_ == 10) {
    tick_ = 0;

    EntityPositionManagerInterface *manager = entity_position_manager();

    Position pos = manager->GetEntityPosition(this);
    manager = manager->SetEntityPosition(this,
      Position(pos.x() + 1, pos.y() + 1));
    pos = manager->GetEntityPosition(this);

    std::cout << "Imma monsta! X: " << pos.x() << ", Y: " << pos.y() << std::endl;
  }
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
