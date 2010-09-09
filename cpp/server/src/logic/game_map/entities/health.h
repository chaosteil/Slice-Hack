#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_HEALTH_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_HEALTH_H_

namespace slice_hack {
namespace game_map {
namespace entities {

class Health {
 public:
  Health(int max_health);
  virtual ~Health();

  int health() const;
  int max_health() const;

  void set_health(int health);
  void ChangeHealth(int delta_health);
 
 private:
  int health_;
  const int max_health_;
};

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_HEALTH_H_
