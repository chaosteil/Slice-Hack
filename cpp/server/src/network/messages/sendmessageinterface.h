#ifndef SLICE_HACK_NETWORK_MESSAGES_SENDMESSAGEINTERFACE_H_
#define SLICE_HACK_NETWORK_MESSAGES_SENDMESSAGEINTERFACE_H_

namespace slice_hack {
namespace network {
namespace messages {

class SendMessageInterface {
 public:
  virtual ~SendMessageInterface() {}
 protected:
  SendMessageInterface() {}
};

}  // namespace messages
}  // namespace network
}  // namespace slice_hack

#endif  // SLICE_HACK_NETWORK_MESSAGES_SENDMESSAGEINTERFACE_H_
