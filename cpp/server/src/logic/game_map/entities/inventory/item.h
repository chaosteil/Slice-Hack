#ifndef SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_INVENTORY_ITEM_H_
#define SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_INVENTORY_ITEM_H_

#include <string>

namespace slice_hack {
namespace game_map {
namespace entities {
namespace inventory {

class Item {
 public:
  enum Type {
    kNone = 0,
    kSword = 1,
    kHat = 2
  };

  Item(Type type, int value, const std::string &gfx);
  virtual ~Item();

  Type type() const;
  int value() const;
  const std::string &gfx() const;

 private:
  Type type_;
  int value_;
  const std::string &gfx_;
};

}  // namespace inventory
}  // namespace entities
}  // namespace game_map
}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_GAME_MAP_ENTITIES_INVENTORY_ITEM_H_
