#include "joystick.h"
#include "config.h"
Joystick::Joystick(int ce, int ss)
{
    _driver = new RH_NRF24(ce, ss);

    _manager = new RHReliableDatagram(*_driver, JOYSTICK_ADDRESS);
}

bool Joystick::init()
{
    int buttons[]={CHANNEL_1_PIN, CHANNEL_2_PIN, CHANNEL_3_PIN, CHANNEL_4_PIN, CHANNEL_5_PIN, CHANNEL_6_PIN, CHANNEL_7_PIN};
    _x = JoyStick_X_PIN;
    _y = JoyStick_Y_PIN;
    _buttons = buttons;
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

    if (USE_PULLUP == 1)
    {
        for (int i = 0; i < _btnLen; i++)
        {
            pinMode(_buttons[i], INPUT_PULLUP);
        }
    }
    return res;
}

void Joystick::send()
{
    byte joystick[2 + 1 + _btnLen];

    joystick[0] = map(analogRead(_x), 0, 1023, 0, 255);
    joystick[1] = map(analogRead(_y), 0, 1023, 0, 255);

    joystick[2] = _btnLen;
    for (int i = 0; i < _btnLen; i++)
    {
        if (_buttons[i] != -1)
            joystick[i + 2 + 1] = digitalRead(_buttons[i]);
    }
#if CHANNELS_DEBUG == 1
    if (__debug_timeout < millis())
    {
        Serial.println("-----------------------------");
        Serial.print("X:");
        Serial.print(joystick[0]);
        Serial.print(" Y:");
        Serial.println(joystick[1]);
        for (int i = 0; i < _btnLen; i++)
        {
            Serial.print("C");
            Serial.print(i+1);
            Serial.print(": ");
            Serial.println(joystick[i + 2 + 1]);
        }
        __debug_timeout=millis()+CHANNELS_DEBUG_INTERVAL;
    }
#endif

    _manager->sendtoWait(joystick, sizeof(joystick), 255);
}
