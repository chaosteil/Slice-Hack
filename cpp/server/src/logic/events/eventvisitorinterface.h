#ifndef SLICE_HACK_LOGIC_EVENTS_EVENTVISITORINTERFACE_H_
#define SLICE_HACK_LOGIC_EVENTS_EVENTVISITORINTERFACE_H_

namespace slice_hack {
namespace events {

class AttackEvent;
class ChatEvent;
class EnterEvent;
class ItemUseEvent;
class LeaveEvent;
class MoveEvent;
class LoginEvent;

class EventVisitorInterface {
 public:
  EventVisitorInterface() {}
  virtual ~EventVisitorInterface() {}

  virtual void Visit(AttackEvent *attack_event) = 0;
  virtual void Visit(ChatEvent *chat_event) = 0;
  virtual void Visit(EnterEvent *enter_event) = 0;
  virtual void Visit(ItemUseEvent *itemuse_event) = 0;
  virtual void Visit(LeaveEvent *leave_event) = 0;
  virtual void Visit(MoveEvent *move_event) = 0;
  virtual void Visit(LoginEvent *login_event) = 0;
};

}  // namespace events 
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_EVENTVISITORINTERFACE_H_
