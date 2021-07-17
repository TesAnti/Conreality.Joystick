#include "joystick.h"
#include "config.h"
Joystick::Joystick(int ce, int ss)
{
    _driver = new RH_NRF24(ce, ss);

    _manager = new RHReliableDatagram(*_driver, JOYSTICK_ADDRESS);
}
#define CONFIURE_CHANNEL(A)                       \
    if (CHANNEL_##A##_USE_PULLUP)                 \
        pinMode(CHANNEL_##A##_PIN, INPUT_PULLUP); \
    _buttons[A - 1] = CHANNEL_##A##_PIN;          \
    _buttonAnalog[A - 1] = CHANNEL_##A##_ANALOG;

bool Joystick::init()
{
    CONFIURE_CHANNEL(1);
    CONFIURE_CHANNEL(2);
    CONFIURE_CHANNEL(3);
    CONFIURE_CHANNEL(4);
    CONFIURE_CHANNEL(5);
    CONFIURE_CHANNEL(6);
    CONFIURE_CHANNEL(7);
    CONFIURE_CHANNEL(8);
    CONFIURE_CHANNEL(9);

    _btnLen = MAX_SUPPORTED_CHANNELS;

    bool res = _manager->init();
    if (Serial.availableForWrite())
    {
        if (res)
        {
            Serial.println("radio initialized");
        }
        else
        {
            Serial.println("radio failed initialization");
        }
    }

    for (int i = 0; i < _btnLen; i++)
    {
        pinMode(_buttons[i], INPUT_PULLUP);
    }
    return res;
}

void Joystick::send()
{
    byte joystick[_btnLen];

    for (int i = 0; i < _btnLen; i++)
    {
        if (_buttons[i] != -1)
        {
            if (_buttonAnalog[i])
                joystick[i] = map(analogRead(_buttons[i]),0,1023,0,255);
            else
                joystick[i] = digitalRead(_buttons[i]);
        }
    }

#if CHANNELS_DEBUG == 1
    if (__debug_timeout < millis())
    {
        Serial.println("-----------------------------");
        for (int i = 0; i < _btnLen; i++)
        {
            Serial.print("C");
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(joystick[i]);
        }
        __debug_timeout = millis() + CHANNELS_DEBUG_INTERVAL;
    }
#endif

    _manager->sendtoWait(joystick, sizeof(joystick), 255);
}
