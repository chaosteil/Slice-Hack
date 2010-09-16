#include "logic/game_map/entities/inventory/itemslot.h"

#include <boost/foreach.hpp>

namespace slice_hack {
namespace game_map {
namespace entities {
namespace inventory {

ItemSlot::ItemSlot() : item_(Item::kNone, 0, ""), quantity_(0) {}

ItemSlot::~ItemSlot() {}

bool ItemSlot::IsItem() const {
  return quantity_ > 0;
}

int ItemSlot::quantity() const {
  return quantity_;
}

const Item &ItemSlot::item() const {
  return item_;
}

std::vector<Item> ItemSlot::RetrieveItems(int quantity) {
  if (quantity > quantity_)
    return std::vector<Item>();

  quantity_ -= quantity;

  std::vector<Item> items;
  for (int i = 0; i < quantity_; i++) {
    items.push_back(Item(item_));
  }

  return items;
}

bool ItemSlot::AddItems(const std::vector<Item> &items) {
  if (items.size() < 0) {
    return true;
  }
  
  if (quantity_ > 0) {
    BOOST_FOREACH (Item item, items) {
      if (item_ != item) {
        return false;
      }
    }
  }

  item_ = items[0];
  quantity_ += items.size();

  return true;
}

}  // namespace inventory
}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack
