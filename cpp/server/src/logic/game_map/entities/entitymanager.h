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
  EntityManager();
  virtual ~EntityManager();

  Entity *SpawnEntity(/* some values */);
  Entity *GetEntity(boost::uuids::uuid id);
  void RemoveEntity(Entity *entity);
 
 private:
  boost::uuids::random_generator generator_;
  std::map<boost::uuids::uuid, Entity *> entities_;
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_
