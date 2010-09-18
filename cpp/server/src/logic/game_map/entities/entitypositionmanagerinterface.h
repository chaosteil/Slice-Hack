#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYPOSITIONMANAGERINTERFACE_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYPOSITIONMANAGERINTERFACE_H_

#include "logic/game_map/position.h"

namespace slice_hack {
namespace game_map {
namespace entities {

class Entity;

class EntityPositionManagerInterface {
 public:
  enum Collision {
    kNoCollision = 0,
    kEntityCollision = 1,
    kMapCollision = 2
  };

  virtual ~EntityPositionManagerInterface() {}
  
  // Returns the new manager of the entity. Switching positions
  // may cause the entity to switch managers, so users
  // should always update the manager after this.
  virtual EntityPositionManagerInterface *SetEntityPosition(Entity *entity,
    const Position &position) = 0;
  virtual void RemoveEntity(Entity *entity) = 0;
  // Must get the position relative to the current level deepness of
  // the manager.
  virtual Position GetEntityPosition(Entity *entity) = 0;
  virtual Collision CanWalk(const Position &position) = 0;

 protected:
  EntityPositionManagerInterface() {}
};

}  // entities
}  // game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYPOSITIONMANAGERINTERFACE_H_
