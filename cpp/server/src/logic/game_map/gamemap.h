#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_

#include <map>

#include "logic/eventloop.h"
#include "logic/game_map/position.h"
#include "logic/game_map/entities/entitypositionmanagerinterface.h"

namespace slice_hack {
namespace game_map {

namespace entities {
class Entity;
class EntityManager;
}  // namespace entities

class GameMapSection;

class GameMap : public EventTickInterface,
                public entities::EntityPositionManagerInterface {
 public:
  GameMap(int width, int height, int section_width, int section_height);
  virtual ~GameMap();

  int width() const;
  int height() const;

  GameMapSection *GetSectionFromPosition(const Position &position);
  GameMapSection *GetSectionFromEntity(entities::Entity *entity);

  virtual void Run();
  virtual entities::EntityPositionManagerInterface *SetEntityPosition(
    entities::Entity *entity,
    const Position &position);
  virtual void RemoveEntity(entities::Entity *entity);

 private:
  const int width_, height_;
  const int section_width_, section_height_;
  entities::EntityManager *entity_manager_;

  std::map<Position, GameMapSection*> sections_;
  std::map<entities::Entity *, GameMapSection*> entities_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
