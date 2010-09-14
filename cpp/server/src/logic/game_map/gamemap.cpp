#include "logic/game_map/gamemap.h"

#include <boost/foreach.hpp>
#include "logic/game_map/entities/entity.h"
#include "logic/game_map/entities/entitymanager.h"
#include "logic/game_map/gamemapsection.h"

namespace slice_hack {
namespace game_map {

GameMap::GameMap(int width, int height, int section_width, int section_height)
    : EventTickInterface(),
      entities::EntityPositionManagerInterface(),
      width_(width), height_(height),
      section_width_(section_width), section_height_(section_height),
      entity_manager_(new entities::EntityManager()),
      sections_(width * height) {

  // Initialize all sections
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      sections_.at(y * width + x) = 
        new GameMapSection(Position(x, y), section_width_, section_height_,
                           entity_manager_,
                           this);
    }
  }

  // TODO(Chaosteil): Randomize terrain for sections.

  // Test entity
  entities::Entity *entity = entity_manager_->SpawnEntity();
  GetSectionFromPosition(Position(0, 0))->SetEntityPosition(entity,
                                                            Position(0, 0));
}

GameMap::~GameMap() {
  BOOST_FOREACH (GameMapSection *section, sections_) {
    delete section;
  }

  delete entity_manager_;
}

int GameMap::width() const {
  return width_;
}

int GameMap::height() const {
  return height_;
}

GameMapSection *GameMap::GetSectionFromPosition(const Position &position) {
  return sections_.at(position.y() * width_ + position.x());
}

GameMapSection *GameMap::GetSectionFromEntity(entities::Entity *entity) {
  return entities_[entity];
}

void GameMap::Run() {
  BOOST_FOREACH (GameMapSection *section, sections_) {
    section->Run();
  }
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

}  // namespace game_map
}  // namespace slice_hack
