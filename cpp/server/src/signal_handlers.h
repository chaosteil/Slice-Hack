#ifndef SLICE_HACK_SIGNAL_HANDLERS_H_
#define SLICE_HACK_SIGNAL_HANDLERS_H_

namespace signal_handlers {

void Init();
void HandlerSIGINT(int signal);

}  // namespace signal_handlers

#endif  // SLICE_HACK_SIGNAL_HANDLERS_H_