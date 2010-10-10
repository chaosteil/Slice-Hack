#ifndef SLICE_HACK_LOGIC_GAME_H_
#define SLICE_HACK_LOGIC_GAME_H_

#include <queue>

#include "logic/events/eventvisitorinterface.h"
#include "logic/eventloop.h"

namespace slice_hack {

namespace game_map {

namespace entities {
class EntityManager;
};  // namespace entities

class GameMap;
}  // namespace game_map

namespace events {
class Event;
}  // namespace events

class Game : public events::EventVisitorInterface,
             public EventTickInterface {
 public:
  Game(game_map::entities::EntityManager *entity_manager);
  virtual ~Game();

  virtual void AddEvent(events::Event *event);
  virtual void Run();

  virtual void Visit(events::AttackEvent *attack_event);
  virtual void Visit(events::ChatEvent *chat_event);
  virtual void Visit(events::EnterEvent *enter_event);
  virtual void Visit(events::ItemUseEvent *itemuse_event);
  virtual void Visit(events::LeaveEvent *leave_event);
  virtual void Visit(events::MoveEvent *move_event);

  virtual game_map::GameMap *map() const;
 
 private:
  std::queue<events::Event*> events_;
  game_map::GameMap *map_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_H_
