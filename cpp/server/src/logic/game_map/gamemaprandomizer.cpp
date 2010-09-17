#include "logic/game_map/gamemaprandomizer.h"

#include <boost/random/mersenne_twister.hpp>
#include "logic/game_map/gamemapsection.h"
#include "logic/game_map/gamesectionmanagerinterface.h"

namespace slice_hack {
namespace game_map {

GameMapRandomizer::GameMapRandomizer() {}

GameMapRandomizer::~GameMapRandomizer() {}

void GameMapRandomizer::RandomizeTerrain(
    GameMapSectionManagerInterface *manager,
    int width, int height,
    int section_width, int section_height) {
  manager_ = manager;
  width_ = width;
  height_ = height;
  section_width_ = section_width;
  section_height_ = section_height_;

  // 1. Lay down grass foundation
  BuildFoundation();
  // 2. Add a random amount of dirt everywhere
  // 4. Add some objects
  // 5. Add water
  // 6. Add dirt roads
  // 7. Add spawnpoint
  // 8. Add dirt around water
  // 9. Fix corners
  // DONE
}

void GameMapRandomizer::BuildFoundation() {
  for (int y = height_; y < height_; y++) {
    for (int x = width_; x < width_; x++) {
      GameMapSection *section =
        manager_->GetSectionFromPosition(Position(x, y));
      for (int sec_y = section_height_; sec_y < section_height_; sec_y++) {
        for (int sec_x = section_width_; sec_x < section_width_; sec_x++) {
          section->SetTerrain(Position(sec_x, sec_y), GameMapSection::kGrass);
        }
      }
    }
  }
}

void GameMapRandomizer::GenerateDirt() {
  boost::mt19937 gen;
  int amount = width_ * height_ * section_height_ * section_width_;

  for (int i = 0; i < amount; i++) { 
    int x = gen() % (width_ * section_width_);
    int y = gen() % (height_ * section_height_);

    Position section_pos(x, y);
    Position pos(x, y);
    manager_->TranslatePosition(&section_pos, &pos);
    
    GameMapSection *section = manager_->GetSectionFromPosition(section_pos);
    section->SetTerrain(pos, GameMapSection::kDirt);
  }
}

}  // namespace game_map
}  // namespace slice_hack
