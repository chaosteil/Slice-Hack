#ifndef SLICE_HACK_LOGIC_EVENTLOOP_H_
#define SLICE_HACK_LOGIC_EVENTLOOP_H_

#include <list>
#include <event.h>

namespace slice_hack {

class EventTickInterface {
 public:
  virtual ~EventTickInterface() {}

  virtual void Run() = 0;

 protected:
  EventTickInterface() {}
};

// Runs our main game loop and routes
// the network logic through here.
class EventLoop {
 public:
  EventLoop();
  virtual ~EventLoop();

  void AddEvent();
  void AddEventTick(EventTickInterface *event_tick_interface);

  void Start(int fps);
  void Stop();

 private:
  static void RunEventTicks(int fd, short event, void *event_loop);
  void Run();

  std::list<EventTickInterface *> event_ticks_;
  event timer_;
  int fps_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTLOOP_H_
