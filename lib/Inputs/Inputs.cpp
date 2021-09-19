#include "Inputs.h"

namespace Inputs {
    Encoder rotaryEncoder(ENCODER_PIN_1, ENCODER_PIN_2);
    int32_t rotaryEncoderInput = 0;
    int32_t rotaryEncoderInputLast = 0;
    Button buttonModeSelect(BUTTON_MODE_SELECT, 25, true, true);

    void init() {
        buttonModeSelect.begin();
    }

    int32_t readEncoder() {
        return (int32_t)(round(rotaryEncoder.read() / 4.0f));
    }

    void resetEncoder() {
        rotaryEncoder.write(0);
        rotaryEncoderInput = 0;
        rotaryEncoderInputLast = 0;
    }
}
