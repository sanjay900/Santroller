#pragma once
#include "./defines.h"
#define TILT_SENSOR MPU_6050 // this can either be none, MPU_6050 or GRAVITY
#define DEVICE_TYPE DIRECT   // this can be either WII or DIRECT
#define OUTPUT_TYPE XINPUT   // this can be either XINPUT or KEYBOARD or GAMEPAD
#define PIN_GREEN_FRET 4
#define PIN_RED_FRET 5
#define PIN_YELLOW_FRET 7
#define PIN_BLUE_FRET 6
#define PIN_ORANGE_FRET 8
#define PIN_START_BUTTON 16
#define PIN_SELECT_BUTTON 9
#define PIN_WHAMMY_POTENIOMETER 18
#define PIN_STRUM_UP_BUTTON 14
#define PIN_STRUM_DOWN_BUTTON 15
#define PIN_DPAD_LEFT_BUTTON 10
#define PIN_DPAD_RIGHT_BUTTON 21
#define PIN_JOYSTICK_X_POTENIOMETER 19
#define PIN_JOYSTICK_Y_POTENIOMETER 20
#define PIN_GRAVITY 11
#define DIRECTION_MODE JOY
// Set this to JOY if your controller has a joystick, and set Joy X and Joy Y to
// the X and Y for your joystick Set this to DPAD if your controller has a DPAD,
// and set Left and Right to left and right on your dpad. Reuse pins for up and
// down and strumming, if required.
#define INVERT_WHAMMY false
// If your whammy bar appears inverted, set this to true to invert the output of your whammy bar.
#define WHAMMY_INITIAL_VALUE 16863
// Set this value to define where 0 is on your whammy bar.
#define FRETS_LED 1
// If this is set to true, the FRET pins will not use pullups, and will require
// a positive voltage to turn on. This allows for the ability to put LEDs in
// series with your frets, and accept HIGH as an input instead of LOW.
// For a list of keyboard bindings, visit
// http://fourwalledcubicle.com/files/LUFA/Doc/151115/html/group___group___u_s_b_class_h_i_d_common.html
#define KEY_GREEN_FRET HID_KEYBOARD_SC_A
#define KEY_RED_FRET HID_KEYBOARD_SC_S
#define KEY_YELLOW_FRET HID_KEYBOARD_SC_J
#define KEY_BLUE_FRET HID_KEYBOARD_SC_K
#define KEY_ORANGE_FRET HID_KEYBOARD_SC_L
#define KEY_WHAMMY HID_KEYBOARD_SC_SEMICOLON_AND_COLON
#define KEY_START HID_KEYBOARD_SC_ENTER
#define KEY_SELECT HID_KEYBOARD_SC_H
#define KEY_LEFT HID_KEYBOARD_SC_LEFT_ARROW
#define KEY_RIGHT HID_KEYBOARD_SC_RIGHT_ARROW
#define KEY_UP HID_KEYBOARD_SC_UP_ARROW
#define KEY_DOWN HID_KEYBOARD_SC_DOWN_ARROW
#define XINPUT_SUBTYPE GUITAR_SUBTYPE
#define MPU_6050_START 35000