#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYPOSITIONMANAGERINTERFACE_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYPOSITIONMANAGERINTERFACE_H_

#include "logic/game_map/position.h"

namespace slice_hack {
namespace game_map {
namespace entities {

class Entity;

class EntityPositionManagerInterface {
 public:
  virtual ~EntityPositionManagerInterface() {}
  
  virtual void SetEntityPosition(Entity *entity, const Position &position) = 0;
  virtual void RemoveEntity(Entity *entity) = 0;

 protected:
  EntityPositionManagerInterface() {}
};

}  // entities
}  // game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITYPOSITIONMANAGERINTERFACE_H_
