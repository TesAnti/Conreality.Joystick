#include <Arduino.h>
#include "joystick.h"

struct JoystickConfig config = DEFAULT_JOYSTICK_CONFIG(5,6);

Joystick joystick;

void setup()
{
  Serial.begin(9600);

  config.channelsDebug=true;

  config.channels[0].pin=A0;
  config.channels[0].name="X";
  config.channels[0].analog=true;
  
  config.channels[1].pin=A1;
  config.channels[1].name="Y";
  config.channels[1].analog=true;
  
  for (int i = 2; i < 3; i++)
  {
    config.channels[i].pin=i;
  }
  
  
  joystick.init(&config);
}

void loop()
{
  joystick.send();
}