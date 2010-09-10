#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_

#include <map>

#include "logic/game_map/position.h"

namespace slice_hack {
namespace game_map {

namespace entities {
class Entity;
}  // namespace entitites

class GameMapSection {
 public:
  GameMapSection(const Position &position, int width, int height);
  virtual ~GameMapSection();

  int width() const;
  int height() const;
  const char *terrain() const;

  void SetTerrain(const Position &pos, char value);
  const Position &position() const;
  Position GetEntityPosition(entities::Entity *entity);

 private:
  const Position position_;
  const int width_, height_;

  char *terrain_;
  std::map<entities::Entity *, Position> entities_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTION_H_
