#ifndef SLICE_HACK_NETWORK_MESSAGES_SENDMESSAGE_H_
#define SLICE_HACK_NETWORK_MESSAGES_SENDMESSAGE_H_

#include <string>
#include <stdint.h>

namespace slice_hack {
namespace network {
namespace messages {

class SendMessage {
 public:
  virtual ~SendMessage();

  const char *buffer() const;

 protected:
  SendMessage(int id);

  void AddString(const std::string &text);
  void AddInt8(int8_t number);
  void AddInt16(int16_t number);
  void AddInt32(int32_t number);
  
 private:
  std::string buffer_;
};

}  // namespace messages
}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_MESSAGES_SENDMESSAGE_H_
