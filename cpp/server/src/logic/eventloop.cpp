#include "logic/eventloop.h"

#include <boost/foreach.hpp>

namespace slice_hack {

EventLoop::EventLoop() : fps_(30), event_base_(event_base_new()) {}

EventLoop::~EventLoop() {
  Stop();

  event_base_free(event_base_);
}

void EventLoop::AddEvent() {}

void EventLoop::AddEventTick(EventTickInterface *event_tick_interface) {
  event_ticks_.push_back(event_tick_interface);
}

void EventLoop::Start(int fps) {
  fps_ = fps;

  // Run once to init the tick
  Run();

  // This is our loop.
  event_base_dispatch(event_base_);
}

void EventLoop::Stop() {
  event_base_loopbreak(event_base_);
}

void EventLoop::RunEventTicks(int fd, short event, void *e_loop) {
  // We just convert back from the void pointer to the event loop
  // and then go.
  EventLoop *event_loop = static_cast<EventLoop*>(e_loop);
  
  event_loop->Run(); 
}

void EventLoop::Run() {
  // We copy the list before processing it.
  // Maybe someone will want to add another EventTickInterface?
  std::list<EventTickInterface *> event_ticks_temp(event_ticks_);
  BOOST_FOREACH (EventTickInterface *eti, event_ticks_temp) {
    eti->Run();
  }

  // Set up our timer.
	timeval tv;
  event_set(&timer_, -1, 0, RunEventTicks, this);
  event_base_set(event_base_, &timer_);

	evutil_timerclear(&tv);
	tv.tv_sec = 0;
	tv.tv_usec = 1000000 / fps_; // Will run at x frames per second

	evtimer_add (&timer_, &tv);
}

}  // namespace slice_hack
