#include "input_guitar.h"
#include "../config/eeprom.h"
#include "mpu6050/mpu.h"
#include "pins/pins.h"
#include <util/delay.h>
#include <stdbool.h>
#include "../util.h"
volatile bool ready = false;
bool isXboxGuitar(void) {
  return config.main.sub_type == XINPUT_GUITAR_SUBTYPE ||
         config.main.sub_type == XINPUT_GUITAR_ALTERNATE_SUBTYPE ||
         config.main.sub_type == XINPUT_GUITAR_BASS_SUBTYPE;
}
bool isPS3Guitar(void) {
  return config.main.sub_type == PS3_GUITAR_GH_SUBTYPE ||
         config.main.sub_type == PS3_GUITAR_RB_SUBTYPE;
}
bool isGuitar(void) { return isXboxGuitar() || isPS3Guitar(); }
void guitar_init(void) {
  if (!isGuitar()) return;
  if (config.main.tilt_type == MPU_6050) {
    while (mympu_open(15) != 0) {}
    enablePCI(config.pins.r_y);
  } else if (config.main.tilt_type == GRAVITY) {
    pinMode(config.pins.r_y, INPUT_PULLUP);
  } else if (config.main.tilt_type == ANALOGUE) {
    pinMode(config.pins.r_y, INPUT);
  }
}
int32_t z;
float y,p,r;
void guitar_tick(controller_t *controller) {
  if (!isGuitar()) return;
  if (config.main.tilt_type == MPU_6050) {
    if (ready) {
      ready = false;
      mympu_update();
      y = mympu.ypr[0] * (65535 / M_PI);
      p = mympu.ypr[1] * (65535 / M_PI);
      r = mympu.ypr[2] * (65535 / M_PI);
      z = (mympu.ypr[config.axis.mpu_6050_orientation / 2] * (65535 / M_PI));
      if (config.axis.mpu_6050_orientation & 1) { z = -z; }
      if (z > 32767) { z = 65535 - z; }
      //Make this into a sensitivity option.
      z = pow(z, 1.05f);
      z = constrain(z, 0, 32767);
      if (isnan(z)) { z = 0; }
    }
    controller->t_x = r;
    controller->t_y = p;
    controller->t_z = y;
    controller->r_y = z;
  } else if (config.main.tilt_type == GRAVITY) {
    controller->r_y = digitalRead(config.pins.r_y) * 32767;
  } else if (config.main.tilt_type == ANALOGUE) {
    controller->r_y = analogRead(config.pins.r_y);
  }
  // Whammy needs to be scaled so that it is picked up
  int32_t whammy = controller->r_x * 2L;
  controller->r_x = constrain(whammy, 0, 32767);
}
ISR(PCINT0_vect) { ready = true; }
#if defined(PCINT1_vect)
ISR(PCINT1_vect) { ready = true; }
ISR(PCINT2_vect) { ready = true; }
#endif