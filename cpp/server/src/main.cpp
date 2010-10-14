#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <time.h>

#include "signal_handlers.h"
#include "logic/game.h"
#include "logic/eventloop.h"
#include "logic/playermanager.h"
#include "logic/game_map/entities/entitymanager.h"
#include "network/server.h"

#include "network/messages/message_in/loginmessage.h"

namespace nmi = slice_hack::network::messages::message_in;

int main(int argc, const char **argv) {
  // Seed the global random number generator
  boost::mt19937 gen;
  gen.seed(time(0));

  // Start up game and logic
  slice_hack::game_map::entities::EntityManager *entity_manager =
    new slice_hack::game_map::entities::EntityManager();
  slice_hack::EventLoop *event_loop = new slice_hack::EventLoop();
  slice_hack::Game *game = new slice_hack::Game(entity_manager);

  // Load up all packets and the player manager
  nmi::LoginMessage *login_message = new nmi::LoginMessage();

  slice_hack::PlayerManager *player_manager =
    new slice_hack::PlayerManager(entity_manager, game);
  player_manager->RegisterMessage(login_message);

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
  delete entity_manager;
  delete player_manager;

  delete login_message;

  return 0;
}
