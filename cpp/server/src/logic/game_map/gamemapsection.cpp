#include "logic/game_map/gamemapsection.h"

#include <iostream>
#include <boost/foreach.hpp>
#include "logic/game_map/gamesectionmanagerinterface.h"
#include "logic/game_map/entities/entitymanager.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {

GameMapSection::GameMapSection(const Position &position,
                               int width, int height,
                               GameMapSectionManagerInterface *gs_manager,
                               entities::EntityManager *entity_manager,
                               entities::EntityPositionManagerInterface *epm)
    : EventTickInterface(),
      EntityPositionManagerInterface(),
      position_(position), width_(width), height_(height),
      game_section_manager_(gs_manager),
      entity_manager_(entity_manager),
      entity_pos_manager_(epm),
      terrain_(new char[width_ * height_]) {

  for (int i = 0; i < width_ * height_; i++) {
    if (i < width_ || i % width_ == 0) {
      terrain_[i] = 'X';
    } else {
      terrain_[i] = ',';
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

std::vector<entities::Entity *> GameMapSection::GetEntitiesOnPosition(
    const Position &position) {

  // Get all entities on the position by going through
  // all entities and pushing them into a vector we return
  std::vector<entities::Entity *> entities;

  // We determine if a section swap is going to happen
  Position new_section_pos(position_); 
  Position new_map_pos(position);
  game_section_manager_->TranslatePosition(&new_section_pos, &new_map_pos);

  // We found another section, so we get the entities from it.
  if (new_section_pos != position_) {
    GameMapSection *far_section =
      game_section_manager_->GetSectionFromPosition(new_map_pos);
    
    return far_section->GetEntitiesOnPosition(new_map_pos);
  }

  typedef std::pair<entities::Entity*, Position> entity_pos_t;
  BOOST_FOREACH (entity_pos_t entity_pos, entities_) {
    if (entity_pos.second == position) {
      entities.push_back(entity_pos.first);
    }
  }

  return entities;
}

void GameMapSection::Run() {
  // First we need to copy all entities to a temp
  // map, so we don't iterate through the original,
  // since we want to modify it while the entity runs
  std::map<entities::Entity *, Position> temp_entities(entities_);

  // We check first if the entity is already removed from this section
  // before processing it.
  typedef std::pair<entities::Entity *, Position> entity_pos_t;
  BOOST_FOREACH (entity_pos_t entity_pos, temp_entities) {
    if (entities_.find(entity_pos.first) ==
        entities_.end()) {
      continue;
    }

    entity_pos.first->Run();
  }
}

entities::EntityPositionManagerInterface *GameMapSection::SetEntityPosition(
    entities::Entity *entity,
    const Position &position) {
  // Notify the original pos manager that there is an entity right here
  if (entity_pos_manager_) {
    entity_pos_manager_->SetEntityPosition(entity, position_);
  }

  // We determine if a section swap is going to happen
  Position new_section_pos(position_); 
  Position new_map_pos(position);
  game_section_manager_->TranslatePosition(&new_section_pos, &new_map_pos);

  // If we have a new section position, we want to first set this new
  // position to the upper entity pos manager, then to one on the same
  // level.
  if (position_ != new_section_pos) {
    RemoveEntity(entity);

    entities::EntityPositionManagerInterface *epm =
      entity_pos_manager_->SetEntityPosition(entity, new_section_pos);

    return epm->SetEntityPosition(entity, new_map_pos);
  }

  // No section swap happened, so we just set to the position we wanted
  entities_[entity] = position;
  entity->set_entity_position_manager(this);

  return this;
}

void GameMapSection::RemoveEntity(entities::Entity *entity) {
  // Notify the original pos manager that this entity needs to be removed
  if (entity_pos_manager_) {
    entity_pos_manager_->RemoveEntity(entity);
  }

  entities_.erase(entity);
}

Position GameMapSection::GetEntityPosition(entities::Entity *entity) {
  return entities_[entity];
}

}  // namespace game_map
}  // namespace slice_hack
