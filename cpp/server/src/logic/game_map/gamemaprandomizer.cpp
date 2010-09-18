#include <iostream>
#include <cmath>
#include "logic/game_map/gamemaprandomizer.h"

#include <boost/random/mersenne_twister.hpp>
#include "logic/game_map/gamemapsection.h"
#include "logic/game_map/gamesectionmanagerinterface.h"

namespace slice_hack {
namespace game_map {

GameMapRandomizer::GameMapRandomizer()
    : manager_(NULL), width_(0), height_(0),
      section_width_(0), section_height_(0) {}

GameMapRandomizer::~GameMapRandomizer() {}

void GameMapRandomizer::RandomizeTerrain(
    GameMapSectionManagerInterface *manager,
    int width, int height,
    int section_width, int section_height) {
  manager_ = manager;
  width_ = width;
  height_ = height;
  section_width_ = section_width;
  section_height_ = section_height;

  // 1. Lay down grass foundation
  BuildFoundation();
  // 2. Add a random amount of dirt everywhere
  GenerateDirt();
  // 4. Add some objects
  AddObjects();
  // 5. Add water
  GenerateWater();
  // 6. Add spawnpoint
  AddSpawnpoint();
  // 7. Add dirt roads
  GenerateRoads();
  // 8. Add dirt around water
  AddWaterDirt();
  // 9. Fix corners for water and dirt
  // DONE
}

void GameMapRandomizer::BuildFoundation() {
  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      GameMapSection *section =
        manager_->GetSectionFromPosition(Position(x, y));
      for (int sec_y = 0; sec_y < section_height_; sec_y++) {
        for (int sec_x = 0; sec_x < section_width_; sec_x++) {
          section->SetTerrain(Position(sec_x, sec_y), GameMapSection::kGrass);
        }
      }
    }
  }
}

void GameMapRandomizer::GenerateDirt() {
  boost::mt19937 gen;
  int amount = (width_ * height_ * section_height_ * section_width_) / 10;

  for (int i = 0; i < amount; i++) { 
    int x = gen() % (width_ * section_width_);
    int y = gen() % (height_ * section_height_);

    DrawPoint(Position(x, y), GameMapSection::kDirt);
  }
}

void GameMapRandomizer::AddObjects() {
  boost::mt19937 gen;
  int amount = width_ * height_ * section_width_;

  for (int i = 0; i < amount; i++) { 
    int x = gen() % (width_ * section_width_);
    int y = gen() % (height_ * section_height_);
    int terrain = gen() % 5;

    DrawPoint(Position(x, y), terrain+28);
  }
}

void GameMapRandomizer::GenerateWater() {
  boost::mt19937 gen;

  int amount = width_ * height_;

  for (int i = 0; i < amount; i++) {
    // Find one center position
    int x = gen() % (width_ * section_width_);
    int y = gen() % (height_ * section_height_);

    // Make 10 zones around this center
    for (int j = 0; j < 10; j++) {
      int margin = 8 - (gen() % 8) + 1;
      int x_topleft = -(gen() % 8-margin) - 1;
      int y_topleft = -(gen() % 8-margin) - 1;
      int x_bottomright = gen() % margin + 1;
      int y_bottomright = gen() % margin + 1;

      for (int height = y_topleft; height < y_bottomright; height++) {
        for (int width = x_topleft; width < x_bottomright; width++) {
          DrawPoint(Position(x+width, y+height), GameMapSection::kWater);
        }
      }
    }
  }
}

void GameMapRandomizer::AddSpawnpoint() {
  Position center((width_ * section_width_) / 2,
                  (height_ * section_height_) / 2);
  const int spawnpoint[11][11] = {
    {  1,  1,  1,  1,  1, 15,  1,  1,  1,  1,  1},
    {  1,  1,  1, 15, 15, 15, 15, 15,  1,  1,  1},
    {  1,  1, 15, 15, 15, 15, 15, 15, 15,  1,  1},
    {  1, 15, 15, 15, 15, 15, 15, 15, 15, 15,  1},
    {  1, 15, 15, 15, 15, 15, 15, 15, 15, 15,  1},
    { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
    {  1, 15, 15, 15, 15, 15, 15, 15, 15, 15,  1},
    {  1, 15, 15, 15, 15, 15, 15, 15, 15, 15,  1},
    {  1,  1, 15, 15, 15, 15, 15, 15, 15,  1,  1},
    {  1,  1,  1, 15, 15, 15, 15, 15,  1,  1,  1},
    {  1,  1,  1,  1,  1, 15,  1,  1,  1,  1,  1} };

  for (int y = -5; y < 6; y++) {
    for (int x = -5; x < 6; x++) {
      DrawPoint(Position(center.x()+x, center.y()+y), spawnpoint[y+5][x+5]);
    }
  }
}

void GameMapRandomizer::GenerateRoads() {
  boost::mt19937 gen;

  int amount = 10;
  int branches = 20;

  // Generate 4 roads starting from the spawnpoint
  for (int i = 0; i < amount; i++) {
    Position pos(width_ * section_width_ / 2, height_ * section_height_ / 2);
    // This is the main direction we are excluding
    int main_dir = gen() % 4;
    for (int j = 0; j < branches; j++) {
      int direction = gen() % 4;

      // Is direction the one we are excluding?
      if (main_dir == direction) {
        direction = (direction + 1) % 4;
      }

      int newpos_x = pos.x();
      int newpos_y = pos.y();

      if (direction == 0) {
        newpos_x += 8;
        while (pos.x() != newpos_x) {
          for (int k = -1; k <= 1; k++){
            DrawPoint(Position(pos.x(), newpos_y+k), GameMapSection::kDirt);
          }
          pos.set_x(pos.x() + 1);
        }
      } else if (direction == 1) {
        newpos_x -= 8;
        while (pos.x() != newpos_x) {
          for (int k = -1; k <= 1; k++){
            DrawPoint(Position(pos.x(), newpos_y+k), GameMapSection::kDirt);
          }
          pos.set_x(pos.x() - 1);
        }
      } else if (direction == 2) {
        newpos_y += 8;
        while (pos.y() != newpos_y) {
          for (int k = -1; k <= 1; k++){
            DrawPoint(Position(newpos_x+k, pos.y()), GameMapSection::kDirt);
          }
          pos.set_y(pos.y() + 1);
        }
      } else if (direction == 3) {
        newpos_y -= 8;
        while (pos.y() != newpos_y) {
          for (int k = -1; k <= 1; k++){
            DrawPoint(Position(newpos_x+k, pos.y()), GameMapSection::kDirt);
          }
          pos.set_y(pos.y() - 1);
        }
      }
    }
  }
}

void GameMapRandomizer::AddWaterDirt() {
  int total_height = height_ * section_height_;
  int total_width = width_ * section_width_;

  for (int y = 0; y < total_height; y++) {
    for (int x = 0; x < total_width; x++) {
      Position section_pos(0, 0);
      Position pos(x, y);
      manager_->TranslatePosition(&section_pos, &pos);

      GameMapSection *section =
        manager_->GetSectionFromPosition(section_pos);

      int terrain_pos = pos.y() * section_width_ + pos.x();
      char tile = section->terrain()[terrain_pos];

      if (tile != GameMapSection::kWater) {
        continue;
      }

      for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++ ){
          Position dirt_section_pos(0, 0);
          Position dirt_pos(x+i, y+j);
          manager_->TranslatePosition(&dirt_section_pos, &dirt_pos);

          section =
            manager_->GetSectionFromPosition(dirt_section_pos);

          if (section == NULL) {
            continue;
          }
          
          terrain_pos = dirt_pos.y() * section_width_ + dirt_pos.x();
          tile = section->terrain()[terrain_pos];

          if (tile == GameMapSection::kWater) {
            continue;
          }

          section->SetTerrain(dirt_pos, GameMapSection::kDirt);
        }
      }
    }
  }
}

void GameMapRandomizer::DrawPoint(const Position &pos, char type) {
  Position section_pos(0, 0);
  Position tile_pos(pos);
  manager_->TranslatePosition(&section_pos, &tile_pos);

  GameMapSection *section =
    manager_->GetSectionFromPosition(section_pos);

  if (section == NULL) {
    return;
  }
  
  section->SetTerrain(tile_pos, type);
}

}  // namespace game_map
}  // namespace slice_hack
