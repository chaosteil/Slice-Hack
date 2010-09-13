#include "logic/game_map/gamemapsection.h"

#include <iostream>
#include <boost/foreach.hpp>
#include "logic/game_map/entities/entitymanager.h"
#include "logic/game_map/entities/entity.h"

namespace slice_hack {
namespace game_map {

GameMapSection::GameMapSection(const Position &position,
                               int width, int height,
                               entities::EntityManager *entity_manager,
                               entities::EntityPositionManagerInterface *epm)
    : EventTickInterface(),
      EntityPositionManagerInterface(),
      position_(position), width_(width), height_(height),
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

Position GameMapSection::GetEntityPosition(entities::Entity *entity) {
  return entities_[entity];
}

std::vector<entities::Entity *> GameMapSection::GetEntitiesOnPosition(
    const Position &position) {

  // Get all entities on the position by going through
  // all entities and pushing them into a vector we return
  std::vector<entities::Entity *> entities;

  typedef std::pair<entities::Entity*, Position> entity_pos_t;
  BOOST_FOREACH (entity_pos_t entity_pos, entities_) {
    if (entity_pos.second == position) {
      entities.push_back(entity_pos.first);
    }
  }

  return entities;
}

void GameMapSection::Run() {
  typedef std::pair<entities::Entity *, Position> entity_pos_t;
  BOOST_FOREACH (entity_pos_t entity_pos, entities_) {
    entity_pos.first->Run();
  }
}

void GameMapSection::SetEntityPosition(entities::Entity *entity,
                                       const Position &position) {
  // Notify the original pos manager that there is an entity right here
  if (entity_pos_manager_) {
    entity_pos_manager_->SetEntityPosition(entity, position_);
  }

  entities_[entity] = position;
  entity->set_entity_position_manager(this);
}

void GameMapSection::RemoveEntity(entities::Entity *entity) {
  // Notify the original pos manager that this entity needs to be removed
  if (entity_pos_manager_) {
    entity_pos_manager_->RemoveEntity(entity);
  }

  entities_.erase(entity);
}

}  // namespace game_map
}  // namespace slice_hack
