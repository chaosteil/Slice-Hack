#ifndef SLICE_HACK_LOGIC_EVENTS_EVENT_H_
#define SLICE_HACK_LOGIC_EVENTS_EVENT_H_

namespace slice_hack {

namespace game_map {
namespace entities {
class Entity;
}  // namespace entities
}  // namespace game_map

namespace events {

class EventVisitorInterface;

// These events are used for player -> server communication.
class Event {
 public:
  virtual ~Event();

  virtual void Accept(EventVisitorInterface *event_visitor) = 0;

  bool global() const;
  game_map::entities::Entity *origin() const;

 protected:
  Event(bool global, game_map::entities::Entity *origin);

 private:
  bool global_;
  game_map::entities::Entity *origin_;
};

}  // namespace events 
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_EVENTS_EVENT_H_
