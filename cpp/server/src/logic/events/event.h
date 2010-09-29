#ifndef SLICE_HACK_LOGIC_EVENTS_EVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_EVENT_H_

namespace slice_hack {
namespace events {

class EventVisitorInterface;

// These events are used for player -> server communication.
class Event {
 public:
  virtual ~Event();

  virtual void Accept(EventVisitorInterface *event_visitor) = 0;

  bool global() const;

 protected:
  explicit Event(bool global);

 private:
  bool global_;
};

}  // namespace events 
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_EVENT_H_
