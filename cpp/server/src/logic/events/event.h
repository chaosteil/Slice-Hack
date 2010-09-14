#ifndef SLICE_HACK_LOGIC_EVENTS_EVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_EVENT_H_

namespace slice_hack {
namespace events {

class EventVisitorInterface;

// These events are used for player -> server communication.
class Event {
 public:
  Event();
  virtual ~Event();

  virtual void accept(EventVisitorInterface *event_visitor_interface) = 0;
};

}  // namespace events 
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_EVENT_H_
