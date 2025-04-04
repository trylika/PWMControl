#include <main.h>

void setup() {
    // for manual analogWrite(PWM_PIN, pwmLevel); this is needed to set frequency to 32kHz
    // TCCR1B = TCCR1B & B11111000 | B00000001;

    Timer1.initialize(PWM_FREQUENCY);
    Timer1.pwm(PWM_PIN, PWM_LEVEL_MIN);

    readSettings();

    Inputs::init();
    Displays::init();
}

void loop() {
    bool updateNeeded = false;

    Inputs::buttonModeSelect.read();
    if (Inputs::buttonModeSelect.wasReleased()) {
        pwmEnabled = !pwmEnabled;

        updateNeeded = true;
    }

    Inputs::rotaryEncoderInput = Inputs::readEncoder();
    if (Inputs::rotaryEncoderInput != Inputs::rotaryEncoderInputLast) {
        int32_t rotaryEncoderInputDiff = Inputs::rotaryEncoderInput - Inputs::rotaryEncoderInputLast;
        Inputs::rotaryEncoderInputLast = Inputs::rotaryEncoderInput;

        pwmLevel+= rotaryEncoderInputDiff;
        pwmLevel = constrain(pwmLevel, PWM_LEVEL_MIN, PWM_LEVEL_MAX);

        updateNeeded = true;
    }

    if (updateNeeded == true) {
        if (pwmEnabled == true) {
            Timer1.setPwmDuty(PWM_PIN, map(pwmLevel, PWM_LEVEL_MIN, PWM_LEVEL_MAX, 0, 1023));
        } else {
            Timer1.setPwmDuty(PWM_PIN, PWM_LEVEL_MIN);
        }
    }

    if (millis() - Displays::lastUpdate > DISPLAY_UPDATE) {
        Displays::update(pwmEnabled, pwmLevel);

        Displays::lastUpdate = millis();
    }

    if (millis() - lastStorageUpdate > PWM_LEVEL_STORAGE_DELAY) {
        saveSettings();

        lastStorageUpdate = millis();
    }
}

void saveSettings() {
    int32_t stored;
    EEPROM.get(PWM_LEVEL_STORAGE_ADDRESS * sizeof(int32_t), stored);

    if (stored != pwmLevel){
        EEPROM.put(PWM_LEVEL_STORAGE_ADDRESS * sizeof(int32_t), pwmLevel);
    }
}

void readSettings() {
    EEPROM.get(PWM_LEVEL_STORAGE_ADDRESS * sizeof(int32_t), pwmLevel);

    if ((pwmLevel < PWM_LEVEL_MIN) || (pwmLevel > PWM_LEVEL_MAX)) {
        pwmLevel = PWM_LEVEL_MIN;
        saveSettings();
    }
}
