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

class GameMapSectionManagerInterface;

class GameMapSection : public EventTickInterface,
                       public entities::EntityPositionManagerInterface {
 public:
  enum Terrain {
    kNothing = 0,
    kGrass = 1,
    kWater = 2,
    kWaterUp = 3,
    kWaterDown = 4,
    kWaterLeft = 5,
    kWaterRight = 6,
    kWaterUpLeft = 7,
    kWaterUpRight = 8,
    kWaterDownLeft = 9,
    kWaterDownRight = 10,
    kWaterInnerUpLeft = 11,
    kWaterInnerUpRight = 12,
    kWaterInnerDownLeft = 13,
    kWaterInnerDownRight = 14,
    kDirt = 15,
    kDirtUp = 16,
    kDirtDown = 17,
    kDirtLeft = 18,
    kDirtRight = 19,
    kDirtUpLeft = 20,
    kDirtUpRight = 21,
    kDirtDownLeft = 22,
    kDirtDownRight = 23,
    kDirtInnerUpLeft = 24,
    kDirtInnerUpRight = 25,
    kDirtInnerDownLeft = 26,
    kDirtInnerDownRight = 27,
    kStone = 28,
    kLog = 29,
    kTreeStump = 30,
    kGrass_Small = 31,
    kGrass_Big = 32
  };
  GameMapSection(const Position &position, int width, int height,
                 GameMapSectionManagerInterface *game_section_manager,
                 entities::EntityManager *entity_manager,
                 entities::EntityPositionManagerInterface *epm);
  virtual ~GameMapSection();

  int width() const;
  int height() const;
  const char *terrain() const;

  void SetTerrain(const Position &pos, char value);
  const Position &position() const;
  std::vector<entities::Entity *> GetEntitiesOnPosition(
    const Position &position);

  virtual void Run();
  virtual entities::EntityPositionManagerInterface *SetEntityPosition(
    entities::Entity *entity,
    const Position &position);
  virtual void RemoveEntity(entities::Entity *entity);
  virtual Position GetEntityPosition(entities::Entity *entity);

 private:
  const Position position_;
  const int width_, height_;

  GameMapSectionManagerInterface *game_section_manager_;

  entities::EntityManager *entity_manager_;
  entities::EntityPositionManagerInterface *entity_pos_manager_;

  char *terrain_;
  std::map<entities::Entity *, Position> entities_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_
