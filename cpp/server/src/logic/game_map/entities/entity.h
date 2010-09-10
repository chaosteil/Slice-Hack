#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITY_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITY_H_

#include <string>
#include "logic/game_map/entities/health.h"

namespace slice_hack {
namespace game_map {
namespace entities {

class Entity {
 public:
  Entity(const std::string &name, const Health &health);
  virtual ~Entity();

  const std::string &name() const;
  const Health &health() ;

  virtual void Run();

 private:
  const std::string name_;
  Health health_;
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITY_H_
