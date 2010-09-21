#include "logic/game_map/entities/player.h"

namespace slice_hack {
namespace game_map {
namespace entities {

Player::Player(const boost::uuids::uuid &id, const std::string &name,
               const std::string &gfx, const Health &health)
    : Entity(id, name, gfx, health) {}

Player::~Player() {}

void Player::Run() {}

}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
