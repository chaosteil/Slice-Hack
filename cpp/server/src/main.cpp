#include <iostream>

#include "logic/game_map/gamemap.h"

int main(int argc, const char **argv) {
  slice_hack::game_map::GameMap *map =
    new slice_hack::game_map::GameMap(20, 20, 20, 20);

  delete map;

  return 0;
}
