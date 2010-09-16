#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_INVENTORY_ITEMSLOT_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_INVENTORY_ITEMSLOT_H_

#include <vector>
#include "logic/game_map/entities/inventory/item.h"

namespace slice_hack {
namespace game_map {
namespace entities {
namespace inventory {

// Limits usage of items in slot
class ItemSlot {
 public:
  ItemSlot();
  virtual ~ItemSlot();

  bool IsItem() const;
  int quantity() const;

  const Item &item() const;
  std::vector<Item> RetrieveItems(int quantity);
  bool AddItems(const std::vector<Item> &items);

 private:
  Item item_;
  int quantity_;
};

}  // namespace inventory
}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_INVENTORY_INVENTORY_H_
