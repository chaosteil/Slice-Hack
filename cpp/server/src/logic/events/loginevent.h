#ifndef SLICE_HACK_LOGIC_EVENTS_LOGINEVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_LOGINEVENT_H_

#include <string>

#include "logic/events/event.h"

namespace slice_hack {
namespace events { 

class LoginEvent : public Event {
 public:
  LoginEvent(const std::string &name);
  virtual ~LoginEvent();

  const std::string &name() const;

  virtual void Accept(EventVisitorInterface *event_visitor);

 private:
  std::string name_;
};

}  // namespace events
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_LOGINEVENT_H_
