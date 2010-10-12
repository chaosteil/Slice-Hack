#ifndef SLICE_HACK_LOGIC_PLAYERMANAGER_H_
#define SLICE_HACK_LOGIC_PLAYERMANAGER_H_

#include <map>

#include "network/clientmanagerinterface.h"
#include "network/messages/messageinterpreter.h"
#include "game_map/entities/entitymanager.h"
#include "logic/events/eventvisitorinterface.h"

namespace slice_hack {

class PlayerManager : public network::ClientManagerInterface,
                      public events::EventVisitorInterface {
 public:
  PlayerManager(game_map::entities::EntityManager *entity_manager);
  virtual ~PlayerManager();

  virtual void AddClient(network::Client *client);
  virtual HandleData HandleBuffer(network::Client *client);
  virtual void RemoveClient(network::Client *client);

  void RegisterMessage(network::messages::MessageInterpreter *interpreter);

  virtual void Visit(events::AttackEvent *attack_event);
  virtual void Visit(events::ChatEvent *chat_event);
  virtual void Visit(events::EnterEvent *enter_event);
  virtual void Visit(events::ItemUseEvent *itemuse_event);
  virtual void Visit(events::LeaveEvent *leave_event);
  virtual void Visit(events::MoveEvent *move_event);

 private:
  std::map<network::Client *, game_map::entities::Entity *> players_;
  game_map::entities::EntityManager *entity_manager_;

  std::map<int, network::messages::MessageInterpreter*> messages_;
};

}  // namespace slice_hack

#endif  // SLICE_HACK_LOGIC_PLAYERMANAGER_H_
