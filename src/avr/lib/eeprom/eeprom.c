#include "eeprom/eeprom.h"
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
static uint8_t EEMEM test = 0;
Configuration_t EEMEM config_pointer = DEFAULT_CONFIG;
const Configuration_t PROGMEM default_config = DEFAULT_CONFIG;
Configuration_t config;
void loadConfig(void) {
  eeprom_read_block(&config, &config_pointer, sizeof(Configuration_t));
  // Do this first, as previous controllers will have their config stored in a different location, and then the following changes will be to an invalid config otherwise.
  if (config.main.version < 8) {
    eeprom_read_block(&config, &test, sizeof(Configuration_t));
  }
  // Check versions, if they aren't the same, a breaking change has happened
  // Check signatures, that way we know if the EEPROM has a valid config
  // If the signatures don't match, then the EEPROM has garbage data
  if (config.main.signature != ARDWIINO_DEVICE_TYPE) {
    memcpy_P(&config, &default_config, sizeof(Configuration_t));
    config.main.version = 0;
  }
  // version 2 adds leds and midi.
  if (config.main.version < 2) {
    memcpy_P(&config.midi, &default_config.midi, sizeof(default_config.midi));
  }
  // Old configs had the subtype for guitars directly, new configs have
  // additional subtypes that get mapped to the guitar subtype
  if (config.main.subType == REAL_GUITAR_SUBTYPE) {
    config.main.subType = XINPUT_GUITAR_HERO_GUITAR;
  }
  // Old configs had the subtype for drums directly, new configs have additional
  // subtypes that get mapped to the drum subtype
  if (config.main.subType == REAL_DRUM_SUBTYPE) {
    config.main.subType = XINPUT_GUITAR_HERO_DRUMS;
  }
  if (config.main.version < 4) {
    memcpy_P(&config.leds, &default_config.leds, sizeof(default_config.leds));
  }
  if (config.main.version < 6) { config.main.pollRate = POLL_RATE; }
  if (config.main.version < 7) { config.rf.rfInEnabled = false; }
  if (config.main.version < CONFIG_VERSION) {
    config.main.version = CONFIG_VERSION;
    eeprom_update_block(&config, &config_pointer, sizeof(Configuration_t));
  }
}
void writeConfigBlock(uint8_t offset, const uint8_t* data, uint8_t len) {
  eeprom_update_block(data, ((uint8_t *)&config_pointer) + offset, len);
}

void resetConfig(void) {
  memcpy_P(&config, &default_config, sizeof(Configuration_t));
  eeprom_update_block(&config, &config_pointer, sizeof(Configuration_t));
}