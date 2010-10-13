#include "logic/game.h"

#include <iostream>
#include <boost/foreach.hpp>
#include "logic/game_map/gamemap.h"
#include "logic/events/event.h"

#include "logic/events/attackevent.h"
#include "logic/events/chatevent.h"
#include "logic/events/itemuseevent.h"
#include "logic/events/moveevent.h"
#include "logic/events/eventmanagerinterface.h"

namespace slice_hack {

Game::Game(game_map::entities::EntityManager *entity_manager)
    : events::EventVisitorInterface(),
      EventTickInterface(),
      // TODO(Chaosteil): Get values from settings
      map_(new game_map::GameMap(10, 10, 20, 20, entity_manager)) {}

Game::~Game() {
  delete map_;
}

void Game::AddEvent(events::Event *event,
                    events::EventManagerInterface *event_manager) {
  events_.push(ev_evman_t(event, event_manager));
}

void Game::Run() {
  // 1. Drain event queue. We want to copy the original queue,
  //    so it can be filled why it is running.
  std::queue<ev_evman_t> events_temp(events_);
  while (!events_.empty()) {
    events_.pop();
  }
  
  while (!events_temp.empty()) {
    // TODO(Chaosteil): Do some logic.
    ev_evman_t event = events_temp.front();
    events_temp.pop();

    event.second->CleanEvent(event.first);
  }

  // 2. Run NPC logic.
  map_->Run();
}

void Game::Visit(events::AttackEvent *attack_event) {}

void Game::Visit(events::ChatEvent *attack_event) {}

void Game::Visit(events::EnterEvent *enter_event) {}

void Game::Visit(events::ItemUseEvent *itemuse_event) {}

void Game::Visit(events::LeaveEvent *leave_event) {}

void Game::Visit(events::MoveEvent *move_event) {}

void Game::Visit(events::LoginEvent *login_event) {}

game_map::GameMap *Game::map() const {
  return map_;
}

}  // namespace slice_hack
