#include "logic/game_map/entities/inventory/item.h"

namespace slice_hack {
namespace game_map {
namespace entities {
namespace inventory {

Item::Item(Type type, int value, const std::string &gfx)
    : type_(type), value_(value), gfx_(gfx) {}

Item::~Item() {}

Item::Type Item::type() const {
  return type_;
}

int Item::value() const {
  return value_;
}

const std::string &Item::gfx() const {
  return gfx_;
}

}  // namespace inventory
}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
