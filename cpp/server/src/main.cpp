#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <time.h>

#include "signal_handlers.h"
#include "logic/game.h"
#include "logic/eventloop.h"

int main(int argc, const char **argv) {
  // Seed the global random number generator
  boost::mt19937 gen;
  gen.seed(time(0));

  // Start up game and logic
  slice_hack::EventLoop *event_loop = new slice_hack::EventLoop();
  slice_hack::Game *game = new slice_hack::Game();

  event_loop->AddEventTick(game);

  // Enable our signal handlers before running
  signal_handlers::Init();
  
  std::cout << "Starting game..." << std::endl;
  
  // We want our game to run on 30 fps serverside
  event_loop->Start(30);

  std::cout << "Quitting game..." << std::endl;

  delete game;
  delete event_loop;

  return 0;
}
