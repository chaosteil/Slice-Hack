#ifndef SLICE_HACK_LOGIC_EVENTS_EVENTMANAGERINTERFACE_H_
#define SLICE_HACK_LOGIC_EVENTS_EVENTMANAGERINTERFACE_H_

namespace slice_hack {
namespace events {

class Event;

class EventManagerInterface {
 public:
  virtual ~EventManagerInterface() {}

  virtual void CleanEvent(Event *event) = 0;

 protected:
  EventManagerInterface() {}
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_EVENTMANAGERINTERFACE_H_
