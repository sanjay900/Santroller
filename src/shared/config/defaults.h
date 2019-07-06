#pragma once
#include "./defines.h"
#define PROTOCOL_VERSION 0
#define TILT_SENSOR MPU_6050
#define DEVICE_TYPE WII
#define OUTPUT_TYPE GAMEPAD_SUBTYPE
#define POLL_RATE 1
// Thresholds
#define TRIGGER_THRESHOLD 12767
#define JOY_THRESHOLD 12767
#define INVERSIONS                                                             \
  { false, false, false, false, true, false }
// Set this if you have inverted your frets to make it easier to wire leds
// inline
#define FRETS_LED true
#define MAP_JOY_TO_DPAD true
// If this is set to true, the FRET pins will not use pullups, and will require
// a positive voltage to turn on. This allows for the ability to put LEDs in
// series with your frets, and accept HIGH as an input instead of LOW.
// For a list of keyboard bindings, visit
// http://fourwalledcubicle.com/files/LUFA/Doc/151115/html/group___group___u_s_b_class_h_i_d_common.html
#define EMPTY                                                                  \
  { INVALID_PIN, INVALID_PIN }
#define KEYS                                                                   \
  {                                                                            \
    0x04, 0x16, 0x0d, 0x0e, 0x0f, 0x33, 0x28, 0x0b, 0x50, 0x4f, 0x52, 0x51,    \
        0x51, INVALID_PIN, INVALID_PIN, INVALID_PIN, INVALID_PIN, EMPTY,       \
        EMPTY, EMPTY, EMPTY,                                                   \
  }

// Set this value to define the orientation of your mpu6050
#define MPU_6050_ORIENTATION NEGATIVE_X
#if defined(__AVR_ATmega328P__)
#  define MPU_6050_INTERRUPT_PIN 2
#else
#  define MPU_6050_INTERRUPT_PIN 10
#endif
#define PINS                                                                   \
  {                                                                            \
    14, 15, INVALID_PIN, INVALID_PIN, 16, 9, INVALID_PIN, INVALID_PIN, 8,      \
        INVALID_PIN, INVALID_PIN, INVALID_PIN, 4, 5, 6, 7, INVALID_PIN,        \
        INVALID_PIN, 19, 20, 18, INVALID_PIN, MPU_6050_INTERRUPT_PIN           \
  }
#define FIRMWARE GUITAR_DEVICE_TYPE