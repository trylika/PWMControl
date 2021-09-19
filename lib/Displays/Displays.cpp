#include "Displays.h"

namespace Displays {
    TM1637Display display = TM1637Display(DISPLAY_CLK, DISPLAY_DIO);
    unsigned long lastUpdate = 0;

    void init() {
        display.setBrightness(2, true); // 1 - 7
        display.setSegments(displayFull);
        display.setSegments(displayClear);
    }

    void update(bool enabled, uint32_t data) {
        display.showNumberDecEx(data, displayNoDot, false, 3, 1);

        if (enabled) {
            display.setSegments(displayEnabled, 1, 0);
        } else {
            display.setSegments(displayDisabled, 1, 0);
        }
    }
}
