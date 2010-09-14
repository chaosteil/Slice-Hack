#ifndef SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTIONMANAGERINTERFACE_H_
#define SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTIONMANAGERINTERFACE_H_

namespace slice_hack {
namespace game_map {

class GameMapSection;
class Position;

class GameMapSectionManagerInterface {
 public:
  virtual ~GameMapSectionManagerInterface() {}

  virtual GameMapSection *GetSectionFromPosition(const Position &position) = 0;
  virtual void TranslatePosition(Position *section_pos,
                                 Position *entity_pos) = 0;

 protected:
  GameMapSectionManagerInterface() {}
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_GAMEMAPSECTIONMANAGERINTERFACE_H_
