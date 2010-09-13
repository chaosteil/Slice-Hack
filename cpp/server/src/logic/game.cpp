#include "logic/game.h"

#include <iostream>
#include "logic/game_map/gamemap.h"
#include "logic/events/event.h"

namespace slice_hack {

Game::Game()
    : events::EventVisitorInterface(),
      EventTickInterface(),
      map_(new game_map::GameMap(10, 10, 20, 20)) {}

Game::~Game() {
  delete map_;
}

void Game::AddEvent(events::Event *event) {
  events_.push(event);
}

void Game::Run() {
  // TODO(Chaosteil):
  // 1. Drain event queue
  // 2. Run NPC logic
}

}  // namespace slice_hack
