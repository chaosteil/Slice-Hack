#include "logic/game_map/gamemap.h"

#include <cmath>
#include <boost/foreach.hpp>
#include "logic/game_map/gamemapsection.h"
#include "logic/game_map/gamemaprandomizer.h"
#include "logic/game_map/entities/entity.h"
#include "logic/game_map/entities/entitymanager.h"

namespace slice_hack {
namespace game_map {

GameMap::GameMap(int width, int height, int section_width, int section_height,
                 entities::EntityManager *entity_manager)
    : EventTickInterface(),
      GameMapSectionManagerInterface(),
      entities::EntityPositionManagerInterface(),
      width_(width), height_(height),
      section_width_(section_width), section_height_(section_height),
      entity_manager_(entity_manager),
      sections_(width * height) {

  // Initialize all sections
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      sections_.at(y * width + x) = 
        new GameMapSection(Position(x, y), section_width_, section_height_,
                           this,
                           entity_manager_,
                           this);
    }
  }

  // Randomize terrain for sections.
  GameMapRandomizer randomizer;
  randomizer.RandomizeTerrain(this, width, height,
                              section_width, section_height);

  // Test Entity
  entities::Entity *entity = entity_manager_->SpawnEntity();
  GameMapSection *section = GetSectionFromPosition(Position(9, 9));
  section->SetEntityPosition(entity, Position(9, 9));
}

GameMap::~GameMap() {
  BOOST_FOREACH (GameMapSection *section, sections_) {
    delete section;
  }
}

int GameMap::width() const {
  return width_;
}

int GameMap::height() const {
  return height_;
}

void GameMap::Run() {
  BOOST_FOREACH (GameMapSection *section, sections_) {
    section->Run();
  }
}

GameMapSection *GameMap::GetSectionFromEntity(entities::Entity *entity) {
  return entities_[entity];
}

GameMapSection *GameMap::GetSectionFromPosition(const Position &position) {
  int pos = position.y() * width_ + position.x();

  if (pos < 0 || pos >= sections_.size()) {
    return NULL;
  }

  return sections_.at(pos);
}

void GameMap::TranslatePosition(Position *section_pos, Position *entity_pos) {
  Position new_section_pos(*section_pos); 
  Position new_entity_pos(*entity_pos);

  // X Position translation
  if (entity_pos->x() < 0 || entity_pos->x() >= width_) {
    int section_offset_x = floor((float)entity_pos->x() / section_width_);
    int section_pos_x = section_pos->x() + section_offset_x;
    int entity_offset_x = -((section_offset_x -
      section_pos->x()) * section_width_);

    new_section_pos.set_x(section_pos_x);
    new_entity_pos.set_x(entity_pos->x() + entity_offset_x);
  }

  // Y Position translation
  if (entity_pos->y() < 0 || entity_pos->y() >= section_height_) {
    int section_offset_y = floor((float)entity_pos->y() / section_height_);
    int section_pos_y = section_pos->y() + section_offset_y;
    int entity_offset_y = -((section_pos_y -
      section_pos->y()) * section_height_);

    new_section_pos.set_y(section_pos_y);
    new_entity_pos.set_y(entity_pos->y() + entity_offset_y);
  }

  // Return back the values
  *section_pos = new_section_pos;
  *entity_pos = new_entity_pos;
}

entities::EntityPositionManagerInterface *GameMap::SetEntityPosition(
    entities::Entity *entity,
    const Position &position) {
  GameMapSection *section = GetSectionFromPosition(position);

  entities_[entity] = section;
  entity->set_entity_position_manager(this);

  return section;
}

void GameMap::RemoveEntity(entities::Entity *entity) {
  entities_.erase(entity);
}

Position GameMap::GetEntityPosition(entities::Entity *entity) {
  GameMapSection *section = GetSectionFromEntity(entity);
  return section->position();
}

entities::EntityPositionManagerInterface::Collision
    GameMap::CanWalk(const Position &position) {
  return EntityPositionManagerInterface::kNoCollision;
}

}  // namespace game_map
}  // namespace slice_hack
