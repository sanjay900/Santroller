#pragma once
#include "../../../config/config.h"
#include "../Controller.h"
#include "Output.h"
#include "XInputOutput.h"
#include "KeyboardOutput.h"
#include "GamepadOutput.h"
#include "SerialOutput.h"
#include "../../util.h"
class OutputHandler {
public:
  void process(Controller *controller);
  void init();
  bool ready();
};

extern "C" {
void EVENT_USB_Device_Connect(void);
void EVENT_USB_Device_Disconnect(void);
void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);
void EVENT_USB_Device_StartOfFrame(void);
}