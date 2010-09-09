#ifndef SLICE_HACK_LOGIC_EVENTS_EVENTVISITORINTERFACE_H_
#define SLICE_HACK_LOGIC_EVENTS_EVENTVISITORINTERFACE_H_

namespace slice_hack {
namespace events {

// class SomeEvent;

class EventVisitorInterface {
 public:
  EventVisitorInterface() {}
  virtual ~EventVisitorInterface() {}

  // virtual void visit(SomeEvent) = 0;
};

}  // namespace events 
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_EVENTVISITORINTERFACE_H_
