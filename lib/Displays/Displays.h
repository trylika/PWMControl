#ifndef displays_h
#define displays_h

#include <Arduino.h>
#include <stdint.h>
#include <TM1637Display.h>

#define DISPLAY_CLK 5
#define DISPLAY_DIO 6
#define DISPLAY_UPDATE 250

namespace Displays {
    extern TM1637Display display;
    extern unsigned long lastUpdate;

    const uint8_t displayFull[] = {0b01111111, 0b01111111, 0b01111111, 0b01111111};
    const uint8_t displayNoData[] = {0b01000000, 0b01000000, 0b01000000, 0b01000000};
    const uint8_t displayClear[] = {0b00000000, 0b00000000, 0b00000000, 0b00000000};
    const uint8_t displayNoDot = 0b00000000;
    const uint8_t displayMiddleDot = 0b01000000;
    const uint8_t displayEnabled[] = {0b01001001};
    const uint8_t displayDisabled[] = {0b00000000};

    void init();
    void update(bool enabled, uint32_t data);
}

#endif
