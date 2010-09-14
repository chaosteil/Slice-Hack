#include "logic/game_map/position.h"

namespace slice_hack {
namespace game_map {

Position::Position(int x, int y) : x_(x), y_(y) {}

Position::Position(const Position &position)
    : x_(position.x_), y_(position.y_) {}

Position::~Position() {}

Position Position::operator=(const Position &position) {
  x_ = position.x();
  y_ = position.y();
  return *this;
}

bool Position::operator==(const Position &position) const {
  return x_ == position.x_ && y_ == position.y_;
}

bool Position::operator!=(const Position &position) const {
  return !(*this == position);
}

bool Position::operator<(const Position &position) const {
  if (x_ < position.x_) {
    return true;
  } else if (y_ < position.y_) {
    return true;
  }

  return false;
}

int Position::x() const {
  return x_;
}

int Position::y() const {
  return y_;
}

void Position::set_x(int x) {
  x_ = x;
}

void Position::set_y(int y) {
  y_ = y;
}

}  // namespace game_map
}  // namespace slice_hack
