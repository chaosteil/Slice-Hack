#include "logic/game_map/entities/inventory/item.h"

namespace slice_hack {
namespace game_map {
namespace entities {
namespace inventory {

Item::Item(Type type, int value, const std::string &gfx)
    : type_(type), value_(value), gfx_(gfx) {}

Item::Item(const Item &item)
    : type_(item.type_), value_(item.value_), gfx_(item.gfx_) {}

Item::~Item() {}

Item &Item::operator=(const Item &item) {
  type_ = item.type_;
  value_ = item.value_;
  gfx_ = item.gfx_;

  return *this;
}

bool Item::operator==(const Item &item) {
  return type_ == item.type_ && value_ == item.value_ && gfx_ == item.gfx_;
}

bool Item::operator!=(const Item &item) {
  return !(*this == item);
}

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
