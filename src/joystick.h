

#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "Arduino.h"
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <SPI.h>
#include "config.h"
#ifndef JOYSTICK_ADDRESS
#define JOYSTICK_ADDRESS 1
#endif

class Joystick
{
private:
    RHReliableDatagram* _manager;
    RH_NRF24* _driver;
    byte _x;
    byte _y;
    int _buttons[MAX_SUPPORTED_CHANNELS];
    bool _buttonAnalog[MAX_SUPPORTED_CHANNELS];
    String _channelNames[MAX_SUPPORTED_CHANNELS];
    int _btnLen;
    uint32_t __debug_timeout = 0;
public:
    Joystick(int ce, int ss);
    bool init();
    void send();
};





#endif