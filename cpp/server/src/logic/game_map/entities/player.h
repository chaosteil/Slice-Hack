#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_PLAYER_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_PLAYER_H_

#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {
namespace entities {

class Player : public Entity {
 public:
  Player(const boost::uuids::uuid &id, const std::string &name,
         const std::string &gfx, const Health &health);
  virtual ~Player();

  virtual void Run();
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_PLAYER_H_
