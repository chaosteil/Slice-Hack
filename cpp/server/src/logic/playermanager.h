#ifndef SLICE_HACK_LOGIC_PLAYERMANAGER_H_
#define SLICE_HACK_LOGIC_PLAYERMANAGER_H_

#include <map>

#include "network/clientmanagerinterface.h"
#include "game_map/entities/entitymanager.h"

namespace slice_hack {

class PlayerManager : public network::ClientManagerInterface {
 public:
  PlayerManager(game_map::entities::EntityManager *entity_manager);
  virtual ~PlayerManager();

  virtual void AddClient(network::Client *client);
  virtual HandleData HandleBuffer(network::Client *client, const char *buffer,
                                  int length);
  virtual void RemoveClient(network::Client *client);

 private:
  std::map<network::Client *, game_map::entities::Entity *> players_;
  game_map::entities::EntityManager *entity_manager_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_PLAYERMANAGER_H_
