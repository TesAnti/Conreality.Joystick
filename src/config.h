#ifndef CONFIG_H
#define CONFIG_H

#include "joystick_config.h"

#ifndef CE_PIN
#define CE_PIN 9
#endif

#ifndef SS_PIN
#define SS_PIN 10
#endif

#ifndef JoyStick_X_PIN
#define JoyStick_X_PIN A0
#endif

#ifndef JoyStick_Y_PIN
#define JoyStick_Y_PIN A1
#endif


#ifndef USE_PULLUP
#define USE_PULLUP 0
#endif


#ifndef CHANNEL_1_PIN
#define CHANNEL_1_PIN -1
#endif

#ifndef CHANNEL_2_PIN
#define CHANNEL_2_PIN -1
#endif

#ifndef CHANNEL_3_PIN
#define CHANNEL_3_PIN -1
#endif

#ifndef CHANNEL_4_PIN
#define CHANNEL_4_PIN -1
#endif

#ifndef CHANNEL_5_PIN
#define CHANNEL_5_PIN -1
#endif

#ifndef CHANNEL_6_PIN
#define CHANNEL_6_PIN -1
#endif

#ifndef CHANNEL_7_PIN
#define CHANNEL_7_PIN -1
#endif






#define MAX_SUPPORTED_CHANNELS 7


#ifndef CHANNELS_DEBUG
#define CHANNELS_DEBUG 0
#endif


#ifndef CHANNELS_DEBUG_INTERVAL
#define CHANNELS_DEBUG_INTERVAL 500
#endif

#endif//h