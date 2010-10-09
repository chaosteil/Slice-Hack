#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <time.h>

#include "signal_handlers.h"
#include "logic/game.h"
#include "logic/eventloop.h"
#include "logic/playermanager.h"
#include "network/server.h"

int main(int argc, const char **argv) {
  // Seed the global random number generator
  boost::mt19937 gen;
  gen.seed(time(0));

  // Start up game and logic
  slice_hack::EventLoop *event_loop = new slice_hack::EventLoop();
  slice_hack::Game *game = new slice_hack::Game();
  slice_hack::PlayerManager *player_manager = new slice_hack::PlayerManager();

  event_loop->AddEventTick(game);

  // Start up network
  slice_hack::network::Server *server = new slice_hack::network::Server();
  if (!server->StartListen(4321, 100, player_manager, event_loop)) {
    // Error!
    std::cout << "Could not start listening." << std::endl;
    return 1;
  }

  // Enable our signal handlers before running
  signal_handlers::Init(event_loop);
  
  std::cout << "Starting game..." << std::endl;
  
  // We want our game to run on 30 fps serverside
  event_loop->Start(30);

  std::cout << "Quitting game..." << std::endl;

  server->StopListen();
  delete server;
  delete game;
  delete event_loop;

  return 0;
}
