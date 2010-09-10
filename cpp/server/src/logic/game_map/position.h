#ifndef SLICE_HACK_LOGIC_GAME_MAP_POSITION_H_
#define SLICE_HACK_LOGIC_GAME_MAP_POSITION_H_

namespace slice_hack {
namespace game_map {

class Position {
 public:
  Position(int x = -1, int y = -1);
  Position(const Position &position);
  ~Position();

  bool operator<(const Position &position) const;

  int x() const;
  int y() const;

  void set_x(int x);
  void set_y(int y);

 private:
  int x_, y_;
};

}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_POSITION_H_
