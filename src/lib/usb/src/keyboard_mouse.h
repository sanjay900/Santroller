#pragma once
#include <stdint.h>
#include "progmem.h"
#define HID_IOF_VARIABLE (1 << 1)
#define HID_IOF_RELATIVE (1 << 2)
#define HID_IOF_ABSOLUTE (0 << 2)
#define Buttons 4
#define MinAxisVal -127
#define MaxAxisVal 127
#define MinPhysicalVal -127
#define MaxPhysicalVal 128
#define AbsoluteCoords false
const PROGMEM uint8_t keyboard_mouse_descriptor[] = {
    0x05, 0x01,                                                                           // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,                                                                           // Usage (Keyboard)
    0xA1, 0x01,                                                                           // Collection (Application)
    0x85, 0x06,                                                                           //   Report ID (6)
    0x05, 0x07,                                                                           //   Usage Page (Kbrd/Keypad)
    0x19, 0xE0,                                                                           //   Usage Minimum (0xE0)
    0x29, 0xE7,                                                                           //   Usage Maximum (0xE7)
    0x15, 0x00,                                                                           //   Logical Minimum (0)
    0x25, 0x01,                                                                           //   Logical Maximum (1)
    0x95, 0x08,                                                                           //   Report Count (8)
    0x75, 0x01,                                                                           //   Report Size (1)
    0x81, 0x02,                                                                           //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x07,                                                                           //   Usage Page (Kbrd/Keypad)
    0x19, 0x00,                                                                           //   Usage Minimum (0x00)
    0x29, 0x67,                                                                           //   Usage Maximum (0x67)
    0x15, 0x00,                                                                           //   Logical Minimum (0)
    0x25, 0x01,                                                                           //   Logical Maximum (1)
    0x95, 0x68,                                                                           //   Report Count (104)
    0x75, 0x01,                                                                           //   Report Size (1)
    0x81, 0x02,                                                                           //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x08,                                                                           //   Usage Page (LEDs)
    0x19, 0x01,                                                                           //   Usage Minimum (Num Lock)
    0x29, 0x05,                                                                           //   Usage Maximum (Kana)
    0x95, 0x05,                                                                           //   Report Count (5)
    0x75, 0x01,                                                                           //   Report Size (1)
    0x91, 0x02,                                                                           //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x95, 0x01,                                                                           //   Report Count (1)
    0x75, 0x03,                                                                           //   Report Size (3)
    0x91, 0x01,                                                                           //   Output (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,                                                                                 // End Collection
    0x05, 0x01,                                                                           // Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                                                                           // Usage (Mouse)
    0xA1, 0x01,                                                                           // Collection (Application)
    0x85, 0x05,                                                                           //   Report ID (5)
    0x09, 0x01,                                                                           //   Usage (Pointer)
    0xA1, 0x00,                                                                           //   Collection (Physical)
    0x05, 0x09,                                                                           //     Usage Page (Button)
    0x19, 0x01,                                                                           //     Usage Minimum (0x01)
    0x29, Buttons,                                                                        //     Usage Maximum (Buttons)
    0x15, 0x00,                                                                           //     Logical Minimum (0)
    0x25, 0x01,                                                                           //     Logical Maximum (1)
    0x95, Buttons,                                                                        //     Report Count (Buttons)
    0x75, 1,                                                                              //     Report Size (1)
    0x81, 0x02,                                                                           //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x75, (8 - (Buttons % 8)),                                                             //     Report Size ((8 - (Buttons % 8))
    0x95, 0x01,                                                                           //     Report Count (1)
    0x81, 0x03,                                                                           //     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,                                                                           //     Usage Page (Generic Desktop Ctrls)
    0x09, 0x30,                                                                           //     Usage (X)
    0x09, 0x31,                                                                           //     Usage (Y)
    0x09, 0x38,                                                                           //     Usage (Wheel)
    0x15, 0x81,                                                                           //     Logical Minimum (-127)
    0x25, 0x7F,                                                                           //     Logical Maximum (127)
    0x95, 0x03,                                                                           //     Report Count (3)
    0x75, 0x08,                                                                           //     Report Size (8)
    0x81, HID_IOF_VARIABLE | (AbsoluteCoords ? HID_IOF_ABSOLUTE:HID_IOF_RELATIVE),        //     Input (Data,Var,Abs|Rel,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x0C,                                                                           //     Usage Page (Consumer)
    0x0A, 0x38, 0x02,                                                                     //     Usage (AC Pan)
    0x16, 0x81, 0xFF,                                                                     //     Logical Minimum (-127)
    0x26, 0x7F, 0x00,                                                                     //     Logical Maximum (127)
    0x95, 0x01,                                                                           //     Report Count (1)
    0x75, 0x08,                                                                           //     Report Size (8)
    0x81, 0x06,                                                                           //     Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                                                                                 //   End Collection
    0xC0,                                                                                 // End Collection
};