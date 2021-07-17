#include "Arduino.h"
#ifndef JOYSTICK_CONFIG_H
#define JOYSTICK_CONFIG_H
//----------------------------------------------
//          FUNDUINO EXAMPLE CONFIGURATION
//          see:https://protosupplies.com/product/funduino-joystick-shield-v1-a/
//          or google: funduino joystick
//----------------------------------------------

//pins for radio module
#define CE_PIN 9
#define SS_PIN 10

//axis pins
#define CHANNEL_1_PIN A0
#define CHANNEL_1_ANALOG true
#define CHANNEL_1_NAME "X axis"

#define CHANNEL_2_PIN A1
#define CHANNEL_2_ANALOG true
#define CHANNEL_2_NAME "Y axis"

//button pins
#define CHANNEL_3_PIN 2
#define CHANNEL_3_NAME "A"

#define CHANNEL_4_PIN 3
#define CHANNEL_4_NAME "B"

#define CHANNEL_5_PIN 4
#define CHANNEL_6_PIN 5
#define CHANNEL_7_PIN 6
#define CHANNEL_8_PIN 7
#define CHANNEL_9_PIN 8


#define CHANNELS_DEBUG 1



#endif