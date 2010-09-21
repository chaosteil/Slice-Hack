#ifndef SLICE_HACK_LOGIC_EVENTLOOP_H_
#define SLICE_HACK_LOGIC_EVENTLOOP_H_

#include <list>
#include <map>
#include <event.h>

namespace slice_hack {

class EventTickInterface;
class EventHandlerInterface;

// Runs our main game loop and routes
// the network logic through here.
class EventLoop {
 public:
  EventLoop();
  virtual ~EventLoop();

  void AddFileEvent(int fd, EventHandlerInterface *event_handler);
  void AddEventTick(EventTickInterface *event_tick_interface);

  void RemoveFileEvent(int fd);

  void Start(int fps);
  void Stop();

 private:
  static void RunEventTicks(int fd, short event, void *event_loop);
  static void HandleFileEvent(int fd, short event, void *event_handler);
  void Run();

  std::map<int, struct event *> file_events_;
  std::list<EventTickInterface *> event_ticks_;
  event timer_;
  int fps_;
  event_base *event_base_;
};

class EventTickInterface {
 public:
  virtual ~EventTickInterface() {}

  virtual void Run() = 0;

 protected:
  EventTickInterface() {}
};

class EventHandlerInterface {
 public:
  enum FileEventType {
    kNone = 0,
    kTimeout = 1,
    kSignal = 2,
    kRead = 3,
    kWrite = 4
  };

  virtual ~EventHandlerInterface() {}

  virtual void HandleEvent(int fd, FileEventType type) = 0;

 protected:
  EventHandlerInterface() {}
};


}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTLOOP_H_
