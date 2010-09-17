#ifndef SLICE_HACK_SIGNAL_HANDLERS_H_
#define SLICE_HACK_SIGNAL_HANDLERS_H_

namespace slice_hack {
class EventLoop;
}  // namespace slice_hack

namespace signal_handlers {

void Init(slice_hack::EventLoop *event_loop);

void SignalHandler(int signal);

}  // namespace signal_handlers

#endif  // SLICE_HACK_SIGNAL_HANDLERS_H_
