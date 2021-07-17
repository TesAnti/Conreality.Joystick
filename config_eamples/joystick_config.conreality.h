#include "Arduino.h"
#ifndef JOYSTICK_CONFIG_H
#define JOYSTICK_CONFIG_H

//----------------------------------------------
//CONREALITY CUSTOM JOYSTICK EXAMPLE CONFIGURATION
//----------------------------------------------


//radionmodule pins
#define CE_PIN 5
#define SS_PIN 6

// X axis
#define CHANNEL_1_PIN A0
#define CHANNEL_1_ANALOG true

// Y axis
#define CHANNEL_2_PIN A1
#define CHANNEL_2_ANALOG true

// trigger
#define CHANNEL_3_PIN 2
#define USE_PULLUP 1

// flashlight
#define CHANNEL_4_PIN 3 
#define USE_PULLUP 1

// laser
#define CHANNEL_5_PIN 4
#define USE_PULLUP 1







#endif