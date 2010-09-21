#ifndef SLICE_HACK_NETWORK_SERVER_H_
#define SLICE_HACK_NETWORK_SERVER_H_

#include "logic/eventloop.h"

namespace slice_hack {
namespace network {

class Server : public EventHandlerInterface {
 public:
  Server();
  virtual ~Server();

  bool StartListen(int port, int max_connections, EventLoop *event_loop);
  void StopListen();

  void HandleEvent(int fd, FileEventType event);
};

}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_SERVER_H_
