#include "signal_handlers.h"

#include <signal.h>
#include <event.h>

#include "logic/eventloop.h"

namespace signal_handlers {

typedef struct SignalData_ {
  slice_hack::EventLoop *event_loop;
} SignalData;

SignalData sig_data;

void Init(slice_hack::EventLoop *event_loop) {
  struct sigaction sig_int;
  sig_data.event_loop = event_loop;

  sig_int.sa_handler = SignalHandler;
  sigemptyset (&sig_int.sa_mask);
  sig_int.sa_flags = 0;
  sigaction (SIGINT, &sig_int, 0);
}

void SignalHandler(int signal) {
  slice_hack::EventLoop *event_loop = sig_data.event_loop;
  event_loop->Stop();
}

}  // namespace signal_handlers
