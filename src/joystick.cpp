#include "joystick.h"
#include "config.h"

#define CONFIURE_CHANNEL(A)                       \
    if (CHANNEL_##A##_USE_PULLUP)                 \
        pinMode(CHANNEL_##A##_PIN, INPUT_PULLUP); \
    _buttons[A - 1] = CHANNEL_##A##_PIN;          \
    _buttonAnalog[A - 1] = CHANNEL_##A##_ANALOG;  \
    _channelNames[A - 1] = CHANNEL_##A##_NAME;

bool Joystick::init(JoystickConfig* config)
{
    _config = config;
    _driver = new RH_NRF24(_config->cePin, _config->ssPin);
    _manager = new RHReliableDatagram(*_driver, JOYSTICK_ADDRESS);
    for (int i = 0; i < MAX_SUPPORTED_CHANNELS; i++)
    {
        if(_config->channels[i].pin==-1)continue;
        if (_config->channels[i].usePullup)
            pinMode(_config->channels[i].pin, INPUT_PULLUP);
        _buttons[i] = _config->channels[i].pin;

        _buttonAnalog[i] = _config->channels[i].analog;
        const char *name = _config->channels[i].name;
        if (name == NULL)
        {
            char *buf = (char *)malloc(5);

            sprintf(buf, "C%d", i);
            _channelNames[i] = buf;
        }else
            _channelNames[i] = name;
    }

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
                joystick[i] = map(analogRead(_buttons[i]), 0, 1023, 0, 255);
            else
                joystick[i] = digitalRead(_buttons[i]);
        }
    }

    if (_config->channelsDebug)
    {
        if (__debug_timeout < millis())
        {
            Serial.println("-----------------------------");
            for (int i = 0; i < _btnLen; i++)
            {
                if(_config->channels[i].pin==-1)continue;
                Serial.print(_channelNames[i]);
                Serial.print(": ");
                Serial.println(joystick[i]);
            }
            __debug_timeout = millis() + _config->channelsDebugInterval;
        }
    }

    _manager->sendtoWait(joystick, sizeof(joystick), 255);
}
