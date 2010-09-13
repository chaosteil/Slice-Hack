#ifndef SLICE_HACK_LOGIC_GAME_H_
#define SLICE_HACK_LOGIC_GAME_H_

#include <queue>

#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {

namespace game_map {
class GameMap;
}  // namespace game_map

namespace events {
class Event;
}  // namespace events

class Game : public events::EventVisitorInterface {
 public:
  Game();
  virtual ~Game();

  void AddEvent(events::Event *event);
  void Run();
 
 private:
  std::queue<events::Event*> events_;
  game_map::GameMap *map_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_H_
