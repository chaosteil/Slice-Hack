#ifndef SLICE_HACK_LOGIC_GAME_H_
#define SLICE_HACK_LOGIC_GAME_H_

#include <queue>

#include "logic/events/event.h"
#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {

class Game : public events::EventVisitorInterface {
 public:
  Game();
  virtual ~Game();

  void AddEvent(events::Event *event);
  void Run();
 
 private:
  std::queue<events::Event*> events_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_H_
