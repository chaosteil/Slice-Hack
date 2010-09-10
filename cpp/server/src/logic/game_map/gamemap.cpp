#include "logic/game_map/gamemap.h"

#include <boost/foreach.hpp>
#include "logic/game_map/entities/entity.h"
#include "logic/game_map/gamemapsection.h"

namespace slice_hack {
namespace game_map {

GameMap::GameMap(int width, int height, int section_width, int section_height)
    : width_(width), height_(height),
      section_width_(section_width), section_height_(section_height) {

  // Initialize all sections
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Position pos(x, y);
      sections_[pos] =
        new GameMapSection(pos, section_width_, section_height_);
    }
  }

  // TODO(Chaosteil): Randomize terrain for sections.
}

GameMap::~GameMap() {}

int GameMap::width() const {
  return width_;
}

int GameMap::height() const {
  return height_;
}

GameMapSection *GameMap::GetSectionFromPosition(const Position &position) {
  return sections_[position];
}

GameMapSection *GameMap::GetSectionFromEntity(entities::Entity *entity) {
  return entities_[entity];
}

}  // namespace game_map
}  // namespace slice_hack
