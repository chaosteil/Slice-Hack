#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPRANDOMIZER_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPRANDOMIZER_H_

namespace slice_hack {
namespace game_map {

class GameMapSectionManagerInterface;

class GameMapRandomizer {
 public:
  GameMapRandomizer();
  virtual ~GameMapRandomizer();

  void RandomizeTerrain(GameMapSectionManagerInterface *manager,
                        int width, int height,
                        int section_width, int section_height);

 private:
  void BuildFoundation();
  void GenerateDirt();
  
  GameMapSectionManagerInterface *manager_;
  int width_, height_;
  int section_width_, section_height_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPRANDOMIZER_H_
