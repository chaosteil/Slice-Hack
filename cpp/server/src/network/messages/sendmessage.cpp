#include "network/messages/sendmessage.h"
#include <netinet/in.h>

namespace slice_hack {
namespace network {
namespace messages {

SendMessage::~SendMessage() {}

const char *SendMessage::buffer(int *length) const {
  if (length != NULL) {
    *length = buffer_.size();
  }

  return buffer_.c_str();
}

SendMessage::SendMessage(int id) {
  AddInt16(id);
}

void SendMessage::AddString(const std::string &text) {
  AddInt16(text.size());
  buffer_.append(text.c_str(), text.size());
}

void SendMessage::AddInt8(int8_t number) {
  buffer_.append(1, number);
}

void SendMessage::AddInt16(int16_t number) {
  int16_t var = htons(number);
  char *var_array = (char*)(void*)&var;
  buffer_.append(var_array, sizeof(var));
}

void SendMessage::AddInt32(int32_t number) {
  int32_t var = htonl(number);
  char *var_array = (char*)(void*)&var;
  buffer_.append(var_array, sizeof(var));
}

}  // namespace messages
}  // namespace network
}  // namespace slice_hack
