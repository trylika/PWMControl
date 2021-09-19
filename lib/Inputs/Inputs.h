#ifndef inputs_h
#define inputs_h

#include <Arduino.h>
#include <Encoder.h>
#include <JC_Button.h>

#define ENCODER_PIN_1 2 // D2
#define ENCODER_PIN_2 3 // D3
#define BUTTON_MODE_SELECT 4 // D4
#define BUTTON_LONG_PRESS 500

namespace Inputs {
    extern Encoder rotaryEncoder;
    extern int32_t rotaryEncoderInput;
    extern int32_t rotaryEncoderInputLast;
    extern Button buttonModeSelect;

    void init();
    int32_t readEncoder();
    void resetEncoder();
}

#endif
