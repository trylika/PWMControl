#ifndef main_h
#define main_h

#include <Arduino.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <Inputs.h>
#include <Displays.h>

#define PWM_FREQUENCY 40 // 40us or 25kHz
#define PWM_PIN 9
#define PWM_LEVEL_MAX 100
#define PWM_LEVEL_MIN 0
#define PWM_LEVEL_STORAGE_ADDRESS 7
#define PWM_LEVEL_STORAGE_DELAY 15000
int32_t pwmLevel = 0;
bool pwmEnabled = false;
unsigned long lastStorageUpdate = 0;

void setup();
void loop();
void saveSettings();
void readSettings();

#endif
