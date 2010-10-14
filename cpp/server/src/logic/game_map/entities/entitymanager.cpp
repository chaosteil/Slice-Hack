#include "logic/game_map/entities/entitymanager.h"

#include <iostream>
#include <boost/foreach.hpp>
#include "logic/game_map/entities/entity.h"
#include "logic/game_map/entities/monster.h"
#include "logic/game_map/entities/player.h"

namespace slice_hack {
namespace game_map {
namespace entities {

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
  typedef std::pair<boost::uuids::uuid, Entity *> uuid_entity_t;
  BOOST_FOREACH (uuid_entity_t uuid_entity, entities_) {
    delete uuid_entity.second;
  }

  entities_.clear();
}

Entity *EntityManager::SpawnEntity(const std::string &name,
                                   EntityType entity_type) {
  boost::uuids::uuid id = boost::uuids::random_generator()();

  Entity *entity = NULL;
  if (entity_type == kEntityMonster) {
    entity = new Monster(id, name, "monster", Health(10));
  } else if (entity_type == kEntityPlayer) {
    entity = new Player(id, name, "player", Health(100));
  } else {
    entity = new Entity(id, name, "entity", Health(1));
  }

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
