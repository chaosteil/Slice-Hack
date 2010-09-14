#include "signal_handlers.h"

#include <signal.h>
#include <event.h>

namespace signal_handlers {

void Init() {
  struct sigaction sig_int;

  sig_int.sa_handler = HandlerSIGINT;
  sigemptyset (&sig_int.sa_mask);
  sig_int.sa_flags = 0;
  sigaction (SIGINT, &sig_int, 0);
}

void HandlerSIGINT(int signal) {
  // TODO(Chaosteil): Find a way to stop the event loop through the method.
  event_loopbreak();
}

}  // namespace signal_handlers
