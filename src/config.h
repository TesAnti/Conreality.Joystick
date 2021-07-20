#ifndef CONFIG_H
#define CONFIG_H
#include "Arduino.h"

#define MAX_SUPPORTED_CHANNELS 9


struct ChannelConfig
{
    int pin;
    bool analog;
    bool usePullup;
    const char* name;
};

struct JoystickConfig
{
    int cePin;
    int ssPin;
    ChannelConfig channels[MAX_SUPPORTED_CHANNELS];
    bool channelsDebug;
    int channelsDebugInterval;
};


#define DEFAULT_JOYSTICK_CONFIG(CE,SS) { \
    .cePin = CE, \
    .ssPin = SS, \
    .channels = { \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL}, \
        {-1, false, false, NULL} \
                 }, \
    .channelsDebug = false, \
    .channelsDebugInterval = 500 \
}



#endif//h