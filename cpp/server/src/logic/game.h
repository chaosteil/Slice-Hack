#ifndef SLICE_HACK_LOGIC_GAME_H_
#define SLICE_HACK_LOGIC_GAME_H_

#include <queue>

#include "logic/events/eventvisitorinterface.h"
#include "logic/eventloop.h"

namespace slice_hack {

namespace game_map {
class GameMap;
}  // namespace game_map

namespace events {
class Event;
}  // namespace events

class Game : public events::EventVisitorInterface,
             public EventTickInterface {
 public:
  Game();
  virtual ~Game();

  virtual void AddEvent(events::Event *event);
  virtual void Run();

  virtual void Visit(events::AttackEvent *attack_event);
  virtual void Visit(events::ChatEvent *chat_event);
  virtual void Visit(events::ItemUseEvent *itemuse_event);
  virtual void Visit(events::MoveEvent *move_event);
 
 private:
  std::queue<events::Event*> events_;
  game_map::GameMap *map_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_H_
