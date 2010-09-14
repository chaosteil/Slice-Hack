#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_

#include <map>
#include <vector>

#include "logic/eventloop.h"
#include "logic/game_map/gamesectionmanagerinterface.h"
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
                public GameMapSectionManagerInterface,
                public entities::EntityPositionManagerInterface {
 public:
  GameMap(int width, int height, int section_width, int section_height);
  virtual ~GameMap();

  int width() const;
  int height() const;

  virtual void Run();

  virtual GameMapSection *GetSectionFromEntity(entities::Entity *entity);
  virtual GameMapSection *GetSectionFromPosition(const Position &position);
  virtual void TranslatePosition(Position *section_pos, Position *entity_pos);

  virtual entities::EntityPositionManagerInterface *SetEntityPosition(
    entities::Entity *entity,
    const Position &position);
  virtual void RemoveEntity(entities::Entity *entity);
  virtual Position GetEntityPosition(entities::Entity *entity);

 private:
  const int width_, height_;
  const int section_width_, section_height_;
  entities::EntityManager *entity_manager_;

  std::vector<GameMapSection*> sections_;
  std::map<entities::Entity *, GameMapSection*> entities_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
