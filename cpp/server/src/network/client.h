#ifndef SLICE_HACK_NETWORK_CLIENT_H_
#define SLICE_HACK_NETWORK_CLIENT_H_

namespace slice_hack {
namespace network {

class Client {
 public:
  Client(int fd);
  virtual ~Client();

  void disconnect();

  bool connected();
  int fd() const;

 private:
  bool connected_;
  const int fd_;
};

}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_CLIENT_H_
