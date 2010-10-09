#include "logic/playermanager.h"

namespace slice_hack {

PlayerManager::PlayerManager() : ClientManagerInterface() {}

PlayerManager::~PlayerManager() {}

void PlayerManager::AddClient(network::Client *client) {}

PlayerManager::HandleData PlayerManager::HandleBuffer(network::Client *client,
                                                      const char *buf,
                                                      int length) {}

void PlayerManager::RemoveClient(network::Client *client) {}

}  // namespace slice_hack
