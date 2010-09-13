#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {
namespace entities {

Entity::Entity(const boost::uuids::uuid &id, const std::string &name,
               const Health &health)
    : id_(id), name_(name), health_(health) {}

Entity::~Entity() {}

const std::string &Entity::name() const {
  return name_;
}

const Health &Entity::health() {
  return health_;
}

const boost::uuids::uuid &Entity::id() const {
  return id_;
}

void Entity::Run() {}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
