#include "logic/game_map/gamemapsection.h"

namespace slice_hack {
namespace game_map {

GameMapSection::GameMapSection(const Position &position,
                               int width, int height)
    : position_(position), width_(width), height_(height),
      terrain_(new char[width_ * height_]) {

  for (int i = 0; i < width_ * height_; i++) {
    if (i < width_ || i % width_ == 0) {
      terrain_[i] = 1;
    } else {
      terrain_[i] = 0;
    }
  }
}

GameMapSection::~GameMapSection() {
  delete[] terrain_;
}

int GameMapSection::width() const {
  return width_;
}

int GameMapSection::height() const {
  return height_;
}

const char *GameMapSection::terrain() const {
  return terrain_;
}

void GameMapSection::SetTerrain(const Position &pos, char value) {
  terrain_[pos.x() + pos.y() * width_] = value;
}

const Position &GameMapSection::position() const {
  return position_;
}

Position GameMapSection::GetEntityPosition(entities::Entity *entity) {
  return entities_[entity];
}

}  // namespace game_map
}  // namespace slice_hack
