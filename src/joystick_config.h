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
#define JoyStick_X_PIN A0
#define JoyStick_Y_PIN A1

//button pins
#define CHANNEL_1_PIN 2
#define CHANNEL_2_PIN 3
#define CHANNEL_3_PIN 4
#define CHANNEL_4_PIN 5
#define CHANNEL_5_PIN 6
#define CHANNEL_6_PIN 7
#define CHANNEL_7_PIN 8


#define CHANNELS_DEBUG 1



#endif