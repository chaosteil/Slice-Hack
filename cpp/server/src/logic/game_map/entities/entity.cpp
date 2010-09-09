#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {
namespace entities {

Entity::Entity(const std::string &name, const Health &health)
    : name_(name), health_(health) {}

Entity::~Entity() {}

const std::string &Entity::name() const {
  return name_;
}

Health &Entity::health() {
  return health_;
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
