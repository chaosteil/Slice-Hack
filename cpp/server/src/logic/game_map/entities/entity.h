#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITY_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITY_H_

#include <string>
#include <boost/uuid/uuid.hpp>
#include "logic/eventloop.h"
#include "logic/game_map/entities/health.h"
#include "logic/game_map/entities/entitypositionmanagerinterface.h"

namespace slice_hack {
namespace game_map {
namespace entities {

class Entity : public EventTickInterface {
 public:
  Entity(const boost::uuids::uuid &id, const std::string &name,
         const Health &health);
  virtual ~Entity();

  const std::string &name() const;
  const Health &health();
  const boost::uuids::uuid &id() const;

  EntityPositionManagerInterface *entity_position_manager() const;
  void set_entity_position_manager(
    EntityPositionManagerInterface *entity_position_manager);

  virtual void Run();

 private:
  const boost::uuids::uuid id_;
  const std::string name_;
  Health health_;

  EntityPositionManagerInterface *entity_position_manager_;
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_ENTITY_H_
