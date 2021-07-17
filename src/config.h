#ifndef CONFIG_H
#define CONFIG_H

#include "joystick_config.h"

#ifndef CE_PIN
#define CE_PIN 9
#endif

#ifndef SS_PIN
#define SS_PIN 10
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

#ifndef CHANNEL_8_PIN
#define CHANNEL_8_PIN -1
#endif

#ifndef CHANNEL_9_PIN
#define CHANNEL_9_PIN -1
#endif


#ifndef CHANNEL_1_ANALOG
#define CHANNEL_1_ANALOG true
#endif

#ifndef CHANNEL_2_ANALOG
#define CHANNEL_2_ANALOG true
#endif

#ifndef CHANNEL_3_ANALOG
#define CHANNEL_3_ANALOG false
#endif

#ifndef CHANNEL_4_ANALOG
#define CHANNEL_4_ANALOG false
#endif

#ifndef CHANNEL_5_ANALOG
#define CHANNEL_5_ANALOG false
#endif

#ifndef CHANNEL_6_ANALOG
#define CHANNEL_6_ANALOG false
#endif

#ifndef CHANNEL_7_ANALOG
#define CHANNEL_7_ANALOG false
#endif

#ifndef CHANNEL_8_ANALOG
#define CHANNEL_8_ANALOG false
#endif

#ifndef CHANNEL_9_ANALOG
#define CHANNEL_9_ANALOG false
#endif


#ifndef CHANNEL_1_USE_PULLUP
#define CHANNEL_1_USE_PULLUP false
#endif

#ifndef CHANNEL_2_USE_PULLUP
#define CHANNEL_2_USE_PULLUP false
#endif

#ifndef CHANNEL_3_USE_PULLUP
#define CHANNEL_3_USE_PULLUP false
#endif

#ifndef CHANNEL_4_USE_PULLUP
#define CHANNEL_4_USE_PULLUP false
#endif

#ifndef CHANNEL_5_USE_PULLUP
#define CHANNEL_5_USE_PULLUP false
#endif

#ifndef CHANNEL_6_USE_PULLUP
#define CHANNEL_6_USE_PULLUP false
#endif

#ifndef CHANNEL_7_USE_PULLUP
#define CHANNEL_7_USE_PULLUP false
#endif

#ifndef CHANNEL_8_USE_PULLUP
#define CHANNEL_8_USE_PULLUP false
#endif

#ifndef CHANNEL_9_USE_PULLUP
#define CHANNEL_9_USE_PULLUP false
#endif



#define MAX_SUPPORTED_CHANNELS 9


#ifndef CHANNELS_DEBUG
#define CHANNELS_DEBUG 0
#endif


#ifndef CHANNELS_DEBUG_INTERVAL
#define CHANNELS_DEBUG_INTERVAL 500
#endif

#endif//h