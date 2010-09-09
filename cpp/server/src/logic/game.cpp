#include "logic/game.h"

namespace slice_hack {

Game::Game() : events::EventVisitorInterface() {}
Game::~Game() {}

void Game::AddEvent(events::Event *event) {
  events_.push(event);
}

void Game::Run() {
  // TODO(Chaosteil):
  // 1. Drain event queue
  // 2. Run NPC logic
}

}  // namespace slice_hack
