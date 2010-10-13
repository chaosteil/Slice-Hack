#include "logic/playermanager.h"

#include <algorithm>
#include "network/client.h"
#include "logic/game_map/entities/entity.h"
#include "logic/game_map/entities/entitymanager.h"
#include "logic/events/event.h"
#include "logic/events/loginevent.h"

namespace en = slice_hack::game_map::entities;
namespace nm = slice_hack::network::messages;

namespace slice_hack {

PlayerManager::PlayerManager(en::EntityManager *entity_manager)
    : ClientManagerInterface(),
      entity_manager_(entity_manager),
      push_event_(false) {}

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

PlayerManager::HandleData PlayerManager::HandleBuffer(network::Client *client) {
  nm::MessageInterpreter::Buffer buffer;

  while (true) {
    int length = 0;
    buffer.buf = client->GetBuffer(&length);
    buffer.length = length;
    buffer.pos = 0;

    int message_id = 0,
        message_length = 0;

    // Message header
    if (!nm::MessageInterpreter::DrainInt16(&message_id, &buffer)) {
      return kIncomplete;
    }

    if (messages_.find(message_id) == messages_.end()) {
      return kInvalid;
    }

    if (!nm::MessageInterpreter::DrainInt16(&message_length, &buffer)) {
      return kIncomplete;
    }

    if (buffer.pos + message_length < length) {
      return kIncomplete;
    }

    nm::MessageInterpreter *interpreter = messages_[message_id];

    // Get message body
    events::Event *event = interpreter->GetEvent(&buffer);

    if (event == NULL) {
      return kInvalid;
    }

    if (buffer.pos > message_length) {
      return kInvalid;
    }

    push_event_ = false;

    // Preliminary handle event
    event->Accept(this);
    
    if (push_event_) {
      // TODO(Chaosteil): Add event to loop, where the system will free the event.
    } else {
      interpreter->CleanEvent(event);
    }

    client->DrainBuffer(message_length);

    client->GetBuffer(&length);

    if (length == 0) {
      break;
    }
  }

  return kOk;
}

void PlayerManager::RemoveClient(network::Client *client) {
  en::Entity *entity = players_[client];

  entity_manager_->RemoveEntity(entity);

  players_.erase(client);
}

void PlayerManager::RegisterMessage(nm::MessageInterpreter *interpreter) {
  messages_[interpreter->id()] = interpreter;
}

void PlayerManager::Visit(events::AttackEvent *attack_event) {
  push_event_ = true;
}

void PlayerManager::Visit(events::ChatEvent *attack_event) {
  push_event_ = true;
}

void PlayerManager::Visit(events::EnterEvent *enter_event) {
  push_event_ = true;
}

void PlayerManager::Visit(events::ItemUseEvent *itemuse_event) {
  push_event_ = true;
}

void PlayerManager::Visit(events::LeaveEvent *leave_event) {
  push_event_ = true;
}

void PlayerManager::Visit(events::MoveEvent *move_event) {
  push_event_ = true;
}

void PlayerManager::Visit(events::LoginEvent *login_event) {
  push_event_ = false;
  std::cout << "User " << login_event->name() << " logged in!" << std::endl;
}

}  // namespace slice_hack
