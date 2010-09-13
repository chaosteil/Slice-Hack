#include "logic/game_map/entities/entitymanager.h"

#include "logic/game_map/entities/entity.h"
#include "logic/game_map/entities/monster.h"

namespace slice_hack {
namespace game_map {
namespace entities {

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

Entity *EntityManager::SpawnEntity(/* some values */) {
  boost::uuids::uuid id = generator_();

  Entity *entity = new Monster(id, "Test", Health(10));

  entities_[id] = entity;

  return entity;
}

Entity *EntityManager::GetEntity(const boost::uuids::uuid &id) {
  return entities_[id];
}

void EntityManager::RemoveEntity(Entity *entity) {
  const boost::uuids::uuid &id = entity->id();
  entities_.erase(id);

  delete entity;
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
