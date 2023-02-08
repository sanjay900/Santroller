#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <stdint.h>

#include "defines.h"
#if __has_include("config_data.h")
#include "config_data.h"
#else

#define CONSOLE_TYPE UNIVERSAL //This can either be UNIVERSAL;MIDI;KEYBOARD_MOUSE
#define DEVICE_TYPE GUITAR
#define RHYTHM_TYPE GUITAR_HERO
#define POLL_RATE 1
#define WINDOWS_USES_XINPUT true

#define LED_TYPE LEDS_DISABLED

#define TILT_ENABLED false

#define RF_ENABLED false
#define RF_ID 0

#define LED_COUNT 0

#define DIGITAL_COUNT 1
#define ADC_COUNT 1
#define ADC_PINS {}

#define PIN_INIT {}

#define TICK_PS3 {}

#define KV_KEY_1 {}
#define KV_KEY_2 {}

#define TICK_XINPUT {}

#define TICK_SHARED {}

#define ARDWIINO_BOARD ""

// Serialise whatever configuration structure we use on the GUI side, so that we can pull it back
#define CONFIGURATION {0}
#define CONFIGURATION_LEN 1

// #define TWI_0_SDA 0
// #define TWI_0_SCL 1
// #define TWI_0_FREQ 400000L
// #define TWI_1_SDA 2
// #define TWI_1_SCL 2
// #define TWI_1_FREQ 400000L

// #define PS2_ACK 0
// #define PS2_ATT 0
// #define RF_IRQ 0
// #define RF_WAKEUP 1

// #define SPI_0_MOSI 0
// #define SPI_0_MISO 1
// #define SPI_0_SCK 1
// #define SPI_0_CPOL 1
// #define SPI_0_CPHA 1
// #define SPI_0_MSBFIRST 0
// #define SPI_0_CLOCK 100000L

// #define SPI_1_MOSI 0
// #define SPI_1_MISO 1
// #define SPI_1_SCK 1
// #define SPI_1_CPOL 1
// #define SPI_1_CPHA 1
// #define SPI_1_MSBFIRST 0
// #define SPI_1_CLOCK 100000L
#endif

// ConsoleType can change due to console detection
extern uint8_t consoleType;
extern const uint8_t config[CONFIGURATION_LEN];
#ifdef __cplusplus
}
#endif
#include "defines.h"
#include "reports/controller_reports.h"
#if DEVICE_TYPE == LIVE_GUITAR
#define DEVICE_TYPE_IS_LIVE_GUITAR true
#else
#define DEVICE_TYPE_IS_LIVE_GUITAR false
#endif
#if DEVICE_TYPE == GUITAR || DEVICE_TYPE == LIVE_GUITAR
#define DEVICE_TYPE_IS_GUITAR true
#define DEVICE_TYPE_IS_DRUM false
#elif DEVICE_TYPE == DRUMS
#define DEVICE_TYPE_IS_GUITAR false
#define DEVICE_TYPE_IS_DRUM true
#else
#define DEVICE_TYPE_IS_GUITAR false
#define DEVICE_TYPE_IS_DRUM false
#endif
#if DEVICE_TYPE == GUITAR || DEVICE_TYPE == DRUMS
    #if RHYTHM_TYPE == GUITAR_HERO
        #define PS3_ID 0x06
    #elif RHYTHM_TYPE == ROCK_BAND
        #define PS3_ID 0x00
    #endif
#else
    #define PS3_ID 0x07
#endif
#if DEVICE_TYPE == GAMEPAD
#define SUB_TYPE XINPUT_GAMEPAD
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == WHEEL
#define SUB_TYPE XINPUT_WHEEL
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == ARCADE_STICK
#define SUB_TYPE XINPUT_ARCADE_STICK
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == GUITAR && RHYTHM_TYPE == GUITAR_HERO
#define SUB_TYPE XINPUT_GUITAR_ALTERNATE
#define PS3_TYPE PS3_GH_GUITAR_PID
#define WII_TYPE WII_RB_GUITAR_PID
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGuitarHeroGuitar_Data_t
#define XBOX_ONE_REPORT XboxOneRockBandGuitar_Data_t
#define PS3_REPORT PS3GuitarHeroGuitar_Data_t
#elif DEVICE_TYPE == GUITAR && RHYTHM_TYPE == ROCK_BAND
#define SUB_TYPE XINPUT_GUITAR_ALTERNATE
#define PS3_TYPE PS3_RB_GUITAR_PID
#define WII_TYPE WII_RB_GUITAR_PID
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputRockBandGuitar_Data_t
#define XBOX_ONE_REPORT XboxOneRockBandGuitar_Data_t
#define PS3_REPORT PS3RockBandGuitar_Data_t
#elif DEVICE_TYPE == LIVE_GUITAR
#define SUB_TYPE XINPUT_GUITAR_ALTERNATE
#define PS3_TYPE PS3WIIU_GHLIVE_DONGLE_PID
#define XINPUT_FLAGS 0x00
#define XINPUT_REPORT XInputGHLGuitar_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3GHLGuitar_Data_t
#elif DEVICE_TYPE == DRUMS && RHYTHM_TYPE == GUITAR_HERO
#define SUB_TYPE XINPUT_DRUMS
#define PS3_TYPE PS3_GH_DRUM_PID
#define WII_TYPE WII_RB_DRUM_PID
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGuitarHeroDrums_Data_t
#define XBOX_ONE_REPORT XboxOneRockBandDrums_Data_t
#define PS3_REPORT PS3GuitarHeroDrums_Data_t
#elif DEVICE_TYPE == DRUMS && RHYTHM_TYPE == ROCK_BAND
#define SUB_TYPE XINPUT_DRUMS
#define PS3_TYPE PS3_RB_DRUM_PID
#define WII_TYPE WII_RB_DRUM_PID
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputRockBandDrums_Data_t
#define XBOX_ONE_REPORT XboxOneRockBandDrums_Data_t
#define PS3_REPORT PS3RockBandDrums_Data_t
#elif DEVICE_TYPE == FLIGHT_STICK
#define SUB_TYPE XINPUT_FLIGHT_STICK
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == DANCE_PAD
#define SUB_TYPE XINPUT_DANCE_PAD
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == ARCADE_PAD
#define SUB_TYPE XINPUT_ARCADE_PAD
#define XINPUT_FLAGS 0x10
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == STAGE_KIT
#define SUB_TYPE XINPUT_STAGE_KIT
#define XINPUT_FLAGS 0x00
#define XINPUT_REPORT XInputGamepad_Data_t
#define XBOX_ONE_REPORT XboxOneGamepad_Data_t
#define PS3_REPORT PS3Gamepad_Data_t
#elif DEVICE_TYPE == DJ_HERO_TURNTABLE
#define SUB_TYPE XINPUT_TURNTABLE
#define PS3_TYPE PS3_DJ_TURNTABLE_PID
#define XINPUT_FLAGS 0x00
#define XINPUT_REPORT XInputTurntable_Data_t
#define XBOX_ONE_REPORT XboxOneTurntable_Data_t
#define PS3_REPORT PS3Turntable_Data_t
#endif
// Xbox One Controller config
#define TEMP 0xFF
#if DEVICE_TYPE == GUITAR
#define XBOX_ONE_VID XBOX_ONE_RB_GUITAR_VID
#define XBOX_ONE_PID XBOX_ONE_RB_GUITAR_PID
#define IDENTIFY_4_SIZE 64
#elif DEVICE_TYPE == DRUMS
#define XBOX_ONE_VID XBOX_ONE_RB_DRUM_VID
#define XBOX_ONE_PID XBOX_ONE_RB_DRUM_PID
#define IDENTIFY_4_SIZE 64
#elif DEVICE_TYPE == LIVE_GUITAR
#define XBOX_ONE_VID XBOX_ONE_GHLIVE_DONGLE_VID
#define XBOX_ONE_PID XBOX_ONE_GHLIVE_DONGLE_PID
#define IDENTIFY_4_SIZE 64
#else
#define XBOX_ONE_VID XBOX_ONE_CONTROLLER_VID
#define XBOX_ONE_PID XBOX_ONE_CONTROLLER_PID
#define IDENTIFY_4_SIZE 46
#endif
extern const uint8_t announce[32];
extern const uint8_t identify_1[64];
extern const uint8_t identify_2[64];
extern const uint8_t identify_3[64];
extern const uint8_t identify_4[IDENTIFY_4_SIZE];
extern const uint8_t identify_5[8];
#define SUPPORTS_KEYBOARD CONSOLE_TYPE == KEYBOARD_MOUSE
#define SUPPORTS_LEDS LED_TYPE == LEDS_APA102 || LED_TYPE == LEDS_WS2812
#define SUPPORTS_MIDI CONSOLE_TYPE == MIDI
#define SUPPORTS_HID CONSOLE_TYPE != MIDI
#define SUPPORTS_PICO defined(ARDUINO_ARCH_RP2040)
#define SUPPORTS_AVR defined(__AVR__)
#define SUPPORTS_TEENSY defined(__arm__) && defined(CORE_TEENSY)
