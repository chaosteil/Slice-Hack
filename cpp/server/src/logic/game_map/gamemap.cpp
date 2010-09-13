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
      entity_manager_(new entities::EntityManager()) {

  // Initialize all sections
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Position pos(x, y);
      sections_[pos] =
        new GameMapSection(pos, section_width_, section_height_,
                           entity_manager_,
                           this);
    }
  }

  // TODO(Chaosteil): Randomize terrain for sections.

  // Test entity
  entities::Entity *entity = entity_manager_->SpawnEntity();
  sections_[Position(0, 0)]->SetEntityPosition(entity, Position(0, 0));
}

GameMap::~GameMap() {
  typedef std::pair<Position, GameMapSection *> pos_section_t;
  BOOST_FOREACH (pos_section_t pos_section, sections_) {
    delete pos_section.second;
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
  return sections_[position];
}

GameMapSection *GameMap::GetSectionFromEntity(entities::Entity *entity) {
  return entities_[entity];
}

void GameMap::Run() {
  typedef std::pair<Position, GameMapSection *> pos_section_t;
  BOOST_FOREACH (pos_section_t pos_section, sections_) {
    pos_section.second->Run();
  }
}

void GameMap::SetEntityPosition(entities::Entity *entity,
                                const Position &position) {
  GameMapSection *section = GetSectionFromPosition(position);

  entities_[entity] = section;
  entity->set_entity_position_manager(this);
}

void GameMap::RemoveEntity(entities::Entity *entity) {
  entities_.erase(entity);
}

}  // namespace game_map
}  // namespace slice_hack
