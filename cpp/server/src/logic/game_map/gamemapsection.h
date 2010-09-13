#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_

#include <map>
#include <vector>

#include "logic/eventloop.h"
#include "logic/game_map/position.h"
#include "logic/game_map/entities/entitypositionmanagerinterface.h"

namespace slice_hack {
namespace game_map {

namespace entities {
class Entity;
class EntityManager;
}  // namespace entitites

class GameMapSection : public EventTickInterface,
                       public entities::EntityPositionManagerInterface {
 public:
  GameMapSection(const Position &position, int width, int height,
                 entities::EntityManager *entity_manager,
                 entities::EntityPositionManagerInterface *epm);
  virtual ~GameMapSection();

  int width() const;
  int height() const;
  const char *terrain() const;

  void SetTerrain(const Position &pos, char value);
  const Position &position() const;
  Position GetEntityPosition(entities::Entity *entity);
  std::vector<entities::Entity *> GetEntitiesOnPosition(
    const Position &position);

  virtual void Run();
  virtual void SetEntityPosition(entities::Entity *entity,
                                 const Position &position);
  virtual void RemoveEntity(entities::Entity *entity);

 private:
  const Position position_;
  const int width_, height_;
  entities::EntityManager *entity_manager_;
  entities::EntityPositionManagerInterface *entity_pos_manager_;

  char *terrain_;
  std::map<entities::Entity *, Position> entities_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_
