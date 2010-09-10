#include "logic/game_map/entities/entitymanager.h"

#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {
namespace entities {

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

Entity *EntityManager::SpawnEntity(/* some values */) {
  Entity *entity = new Entity("Test", Health(10));

  Id id = (Id)entity;

  entities_[id] = entity;

  return entity;
}

Entity *EntityManager::GetEntity(Id id) {
  return entities_[id];
}

void EntityManager::RemoveEntity(Entity *entity) {
  Id id = (Id)entity;
  entities_.erase(id);

  delete entity;
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
