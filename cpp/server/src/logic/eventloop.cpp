#include "logic/eventloop.h"

#include <boost/foreach.hpp>

namespace slice_hack {

EventLoop::EventLoop() : fps_(30) {
  event_init();
}

EventLoop::~EventLoop() {
  Stop();
}

void EventLoop::AddEvent() {}

void EventLoop::AddEventTick(EventTickInterface *event_tick_interface) {
  event_ticks_.push_back(event_tick_interface);
}

void EventLoop::Start(int fps) {
  fps_ = fps;
  RunEventTicks(0, 0, this);

  event_dispatch();
}

void EventLoop::Stop() {
  event_loopbreak();
}

void EventLoop::RunEventTicks(int fd, short event, void *e_loop) {
  EventLoop *event_loop = static_cast<EventLoop*>(e_loop);
  
  event_loop->Run(); 

	timeval tv;
  evtimer_set(&event_loop->timer_, RunEventTicks, event_loop);

	evutil_timerclear(&tv);
	tv.tv_sec = 0;
	tv.tv_usec = 1000000 / event_loop->fps_;

	evtimer_add (&event_loop->timer_, &tv);
}

void EventLoop::Run() {
  BOOST_FOREACH (EventTickInterface *eti, event_ticks_) {
    eti->Run();
  }
}

}  // namespace slice_hack
