
/* This is an arduino code for a timer which is used to pump water and provide
 *  aeration for a hydroponics system
 *  
 *  Written by: Shimon Payyanadan
 *  Project : Hydroponic Urban farming setup
 */


#include <EveryTimer.h>

EveryTimer t;

#define WATER_PUMP 12
#define AIR_PUMP 11

// TURN ON EVERY 1 HOUR , AIR PUMP FIRST FOLLOWED BY WATER PUMP

#define PERIOD_HR 3600000

#define AIR_ON_TIME_DELAY 180000 

#define WATER_ON_TIME 270000       


void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(WATER_PUMP, OUTPUT);
  pinMode(AIR_PUMP, OUTPUT);
  
  digitalWrite(AIR_PUMP, HIGH); //confirming the motor,pump is off at the start
  digitalWrite(WATER_PUMP, HIGH);
  t.Every(PERIOD_HR , motorOn);

}

// the loop function runs over and over again forever
void loop() {
 delay(2000);
 t.Update();                      // wait for a second
}


void motorOn()
{
  digitalWrite(LED_BUILTIN, HIGH);
  
  digitalWrite(AIR_PUMP, LOW);
  delay(AIR_ON_TIME_DELAY);
  
  digitalWrite(WATER_PUMP, LOW);
  delay(WATER_ON_TIME);
  
  digitalWrite(LED_BUILTIN, LOW);
  
  digitalWrite(WATER_PUMP, HIGH);
  digitalWrite(AIR_PUMP, HIGH);

}
