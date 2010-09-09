#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_

namespace slice_hack {
namespace game_map {

class GameMap {
 public:
  GameMap();
  ~GameMap();

  void Init(int width, int height);
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAP_H_
