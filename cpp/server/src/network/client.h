#ifndef SLICE_HACK_NETWORK_CLIENT_H_
#define SLICE_HACK_NETWORK_CLIENT_H_

namespace slice_hack {
namespace network {

namespace messages {
class SendMessageInterface;
}  // namespace messages

class Client {
 public:
  Client(int fd);
  virtual ~Client();

  int fd() const;
  void SendMessage(const messages::SendMessageInterface &send_message);

  void AddBuffer(const char *buf, int length);
  const char *GetBuffer(int *length) const;
  void DrainBuffer(int length);
 
 private:
  const int fd_;
  char *buffer_;
  int buffer_length_;
};

}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_CLIENT_H_
