#include "logic/playermanager.h"

#include "network/client.h"
#include "logic/game_map/entities/entity.h"
#include "logic/game_map/entities/entitymanager.h"

namespace en = slice_hack::game_map::entities;

namespace slice_hack {

PlayerManager::PlayerManager(en::EntityManager *entity_manager)
    : ClientManagerInterface(),
      entity_manager_(entity_manager) {}

PlayerManager::~PlayerManager() {
  while (players_.size() != 0) {
    entity_manager_->RemoveEntity(players_.begin()->second);
    players_.erase(players_.begin());
  }
}

void PlayerManager::AddClient(network::Client *client) {
  en::Entity *entity = entity_manager_->SpawnEntity();
      
  players_[client] = entity;
}

PlayerManager::HandleData PlayerManager::HandleBuffer(network::Client *client,
                                                      const char *buf,
                                                      int length) {}

void PlayerManager::RemoveClient(network::Client *client) {
  en::Entity *entity = players_[client];

  entity_manager_->RemoveEntity(entity);

  players_.erase(client);
}

}  // namespace slice_hack
