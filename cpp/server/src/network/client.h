#ifndef SLICE_HACK_NETWORK_CLIENT_H_
#define SLICE_HACK_NETWORK_CLIENT_H_

namespace slice_hack {
namespace network {

namespace messages {
class SendMessageInterface;
}  // namespace messages

class ClientManagerInterface;

class Client {
 public:
  Client(int fd);
  virtual ~Client();

  int fd() const;
  void SendMessage(const messages::SendMessageInterface &send_message);
 
 private:
  const int fd_;
};

}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_CLIENT_H_
