#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_

#include <map>

#include "logic/game_map/position.h"

namespace slice_hack {
namespace game_map {

namespace entities {
class Entity;
}  // namespace entitites

class GameMap {
 public:
  enum ManagedEntity {
    kManagedEntity = 0,
    kUnmanagedEntity = 1
  };

  GameMap();
  ~GameMap();

 private:
  std::map<Position, entities::Entity *> entities_;
  std::map<entities::Entity *, ManagedEntity> managed_entities_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
