#include "network/messages/messageinterpreter.h"

#include <cstring>
#include <stdint.h>
#include <iostream>

namespace slice_hack {
namespace network {
namespace messages {

MessageInterpreter::~MessageInterpreter() {}

int MessageInterpreter::id() const {
  return id_;
}

MessageInterpreter::MessageInterpreter(int id) : id_(id) {}

bool MessageInterpreter::DrainString(std::string *text, Buffer *buffer) {
  int string_length = 0;

  if (!DrainInt16(&string_length, buffer)) {
    return false;
  }

  if (buffer->pos + string_length > buffer->length) {
    return false;
  }

  if (text != NULL) {
    char *buf = new char[string_length+1];

    strncpy(buf, buffer->buf + buffer->pos, string_length);
    buf[string_length] = '\0';

    text->assign(buf);

    delete[] buf;
  }

  buffer->pos += string_length;
  return true;
}

bool MessageInterpreter::DrainInt8(int *number, Buffer *buffer) {
  if (buffer->pos + sizeof(int8_t) > buffer->length) {
    return false;
  }

  if (number != NULL) {
    int8_t buf = *(const int8_t*)(buffer->buf+buffer->pos);
    *number = buf;
  }

  buffer->pos += sizeof(int8_t);
  return true;
}

bool MessageInterpreter::DrainInt16(int *number, Buffer *buffer) {
  if (buffer->pos + sizeof(int16_t) > buffer->length) {
    return false;
  }

  if (number != NULL) {
    int16_t buf = *(const int16_t*)(buffer->buf+buffer->pos);
    *number = buf;
  }

  buffer->pos += sizeof(int16_t);
  return true;
}

bool MessageInterpreter::DrainInt32(int *number, Buffer *buffer) {
  if (buffer->pos + sizeof(int32_t) > buffer->length) {
    return false;
  }

  if (number != NULL) {
    int32_t buf = *(const int32_t*)(buffer->buf+buffer->pos);
    *number = buf;
  }

  buffer->pos += sizeof(int32_t);
  return true;
}

}  // namespace messages
}  // namespace network
}  // namespace slice_hack
