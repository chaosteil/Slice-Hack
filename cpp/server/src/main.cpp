#include <iostream>

#include "logic/game.h"
#include "logic/eventloop.h"

int main(int argc, const char **argv) {
  slice_hack::EventLoop *event_loop = new slice_hack::EventLoop();
  slice_hack::Game *game = new slice_hack::Game();

  event_loop->AddEventTick(game);

  // We want our game to run on 30 fps serverside
  event_loop->Start(30);

  delete game;
  delete event_loop;

  return 0;
}
