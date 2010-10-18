#include "network/client.h"
#include "network/messages/sendmessage.h"

#include <cstring>
#include <sys/socket.h>

namespace slice_hack {
namespace network {

Client::Client(int fd) : fd_(fd), buffer_(NULL), buffer_length_(0) {}

Client::~Client() {
  if (buffer_) {
    delete[] buffer_;
  }
}

int Client::fd() const {
  return fd_;
}

bool Client::SendMessage(const messages::SendMessage &send_message) {
  int length = 0;
  const char *buffer = send_message.buffer(&length);
  int left = length;

  int sent = 0;
  while (sent < length) {
    int bytes = send(fd_, buffer+sent, left, 0);
    if (bytes == -1) {
      return false;
    }

    sent += bytes;
    left -= bytes;
  }

  return true;
}

void Client::AddBuffer(const char *buf, int length) {
  int buffer_length = buffer_length_ + length;

  char *new_buffer = new char[buffer_length];
  memcpy(new_buffer, buffer_, buffer_length_);
  memcpy(new_buffer+buffer_length_, buf, length);

  if (buffer_) {
    delete[] buffer_;
  }

  buffer_ = new_buffer;
  buffer_length_ = buffer_length;
}

const char *Client::GetBuffer(int *length) const {
  *length = buffer_length_;
  return buffer_;
}

void Client::DrainBuffer(int length) {
  if (length <= 0) {
    return;
  }

  if (length >= buffer_length_) {
    length = buffer_length_;
  }

  if (length == buffer_length_) {
    buffer_length_ = 0;
    delete[] buffer_;
    buffer_ = NULL;

    return;
  }

  int left_bytes = buffer_length_ - length;
  char *new_buffer = new char[left_bytes];
  memcpy(new_buffer, buffer_+length, left_bytes);

  delete[] buffer_;
  buffer_ = new_buffer;
  buffer_length_ = left_bytes;
}

}  // namespace network
}  // namespace slice_hack
