#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_MONSTER_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_MONSTER_H_

#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {
namespace entities {

class Monster : public Entity {
 public:
  Monster(const std::string &name, const Health &health /* loot_table */);
  virtual ~Monster();
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_MONSTER_H_
