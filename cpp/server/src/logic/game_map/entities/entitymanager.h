#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_

#include <map>
#include <stdint.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace slice_hack {
namespace game_map {
namespace entities {

class Entity;

class EntityManager {
 public:
  enum EntityType {
    kEntityNone = 0,
    kEntityMonster = 1,
    kEntityPlayer = 2
  };

  EntityManager();
  virtual ~EntityManager();

  // Entity factory. Assigns the entity a uuid.
  virtual Entity *SpawnEntity(const std::string &name, EntityType type);
  virtual Entity *GetEntity(const boost::uuids::uuid &id);
  virtual void RemoveEntity(Entity *entity);
 
 private:
  std::map<boost::uuids::uuid, Entity *> entities_;
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_
