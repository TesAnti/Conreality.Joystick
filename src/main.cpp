
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include <SPI.h>
#include "joystick.h"


/*---------------------------------------------------*/
/*
  See configuration examples in config_examples folder
*/

#include "config.h"


/*---------------------------------------------------*/


/***
 *                                                            
 *    ,------.            ,--.,--.                            
 *    |  .--. ' ,--,--. ,-|  |`--' ,---.                      
 *    |  '--'.'' ,-.  |' .-. |,--.| .-. |                     
 *    |  |\  \ \ '-'  |\ `-' ||  |' '-' '                     
 *    `--' '--' `--`--' `---' `--' `---'                      
 *         ,--.                      ,--.  ,--.      ,--.     
 *         |  | ,---.,--. ,--.,---.,-'  '-.`--' ,---.|  |,-.  
 *    ,--. |  || .-. |\  '  /(  .-''-.  .-',--.| .--'|     /  
 *    |  '-'  /' '-' ' \   ' .-'  `) |  |  |  |\ `--.|  \  \  
 *     `-----'  `---'.-'  /  `----'  `--'  `--' `---'`--'`--' 
 *                   `---'                                    
 */


Joystick joystick(CE_PIN, SS_PIN);



void setup()
{
  Serial.begin(9600);

  joystick.init();
}

void loop()
{
  joystick.send();
}
