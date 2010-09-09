#include "logic/game_map/entities/health.h"


namespace slice_hack {
namespace game_map {
namespace entities {

Health::Health(int max_health)
    : health_(max_health), max_health_(max_health) {}

Health::~Health() {}

int Health::health() const {
  return health_;
}

int Health::max_health() const {
  return max_health_;
}

void Health::set_health(int health) {
  if (health < 0) {
    health_ = 0;
  } else if (health > max_health_) {
    health_ = max_health_;
  } else {
    health_ = health;
  }
}

void Health::ChangeHealth(int delta_health) {
  set_health(health_ + delta_health);
}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
