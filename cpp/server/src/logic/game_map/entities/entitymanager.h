#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_

#include <map>
#include <stdint.h>

namespace slice_hack {
namespace game_map {
namespace entities {

class Entity;

class EntityManager {
 public:
  typedef int64_t Id;
  EntityManager();
  virtual ~EntityManager();

  Entity *SpawnEntity(/* some values */);
  Entity *GetEntity(Id id);
  void RemoveEntity(Entity *entity);
 
 private:
  std::map<Id, Entity *> entities_;
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYMANAGER_H_
