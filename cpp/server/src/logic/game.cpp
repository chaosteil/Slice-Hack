#include "logic/game.h"

#include <iostream>
#include <boost/foreach.hpp>
#include "logic/game_map/gamemap.h"
#include "logic/events/event.h"

namespace slice_hack {

Game::Game()
    : events::EventVisitorInterface(),
      EventTickInterface(),
      // TODO(Chaosteil): Get values from settings
      map_(new game_map::GameMap(10, 10, 20, 15)) {}

Game::~Game() {
  delete map_;
}

void Game::AddEvent(events::Event *event) {
  events_.push(event);
}

void Game::Run() {
  // 1. Drain event queue. We want to copy the original queue,
  //    so it can be filled why it is running.
  std::queue<events::Event *> events_temp(events_);
  while (!events_.empty()) {
    events_.pop();
  }
  
  while (!events_temp.empty()) {
    // TODO(Chaosteil): Do some logic.
  }

  // 2. Run NPC logic.
  map_->Run();
}

}  // namespace slice_hack
