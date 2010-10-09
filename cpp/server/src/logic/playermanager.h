#ifndef SLICE_HACK_LOGIC_PLAYERMANAGER_H_
#define SLICE_HACK_LOGIC_PLAYERMANAGER_H_

#include "network/clientmanagerinterface.h"

namespace slice_hack {

class PlayerManager : public network::ClientManagerInterface {
 public:
  PlayerManager();
  virtual ~PlayerManager();

  virtual void AddClient(network::Client *client);
  virtual HandleData HandleBuffer(network::Client *client, const char *buffer,
                                  int length);
  virtual void RemoveClient(network::Client *client);
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_PLAYERMANAGER_H_
