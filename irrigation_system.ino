#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN  7  
#define DHTTYPE DHT11 


#define LED_TEMPH 13
#define LED_TEMPM 12
#define LED_TEMPL 11
#define LED_MOISTH 10
#define LED_MOISTM 9
#define LED_MOISTL 8
  
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
void setup(){
  Serial.begin(9600);
  pinMode(6,OUTPUT);
   //pinMode(2,OUTPUT);
    pinMode(5,OUTPUT);
     pinMode (4,OUTPUT);
  digitalWrite(6,HIGH);
  //pinMode(3,LOW);
  //pinMode(4,HIGH);



 

  dht.begin();
  Serial.println("AUTOMATED IRRIGATION CONTROL SYSTEM");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop()
{
 // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);






  int moist=analogRead(0);
//moist=300;
//event.temperature=33;
  if(moist>200)
  {
    analogWrite(LED_MOISTH,138);
    analogWrite(LED_MOISTM,138);
    analogWrite(LED_MOISTL,138);
    //digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    }
    else if((moist>50) && (moist<200))
    {
      analogWrite(LED_MOISTM,138);
      digitalWrite(LED_MOISTH,LOW);
      analogWrite(LED_MOISTL,138);
      //digitalWrite(6,LOW);
          digitalWrite(5,LOW);
    digitalWrite(4,LOW);      
      }  
      else if(moist<50)
      {
        analogWrite(LED_MOISTL,138);
        digitalWrite(LED_MOISTH,LOW);
        digitalWrite(LED_MOISTM,LOW);
        //analogWrite(6,HIGH);
         digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
   
        }
       if(event.temperature<27)
       {
        analogWrite(LED_TEMPL,138);
        digitalWrite(LED_TEMPH,LOW);
        digitalWrite(LED_TEMPM,LOW);
         //nalogWrite(6,HIGH);
          digitalWrite(5,LOW);
    digitalWrite(4,LOW);  
        }
        else if((event.temperature>27) &&(event.temperature<32))
       {
        analogWrite(LED_TEMPM,138);
        analogWrite(LED_TEMPL,138);
        digitalWrite(LED_TEMPH,LOW);
         //analogWrite(6,HIGH);

          digitalWrite(5,LOW);
    digitalWrite(4,LOW);  
        
        }
        else if(event.temperature>32)
       {
        analogWrite(LED_TEMPH,13-8);
        analogWrite(LED_TEMPL,138);
        //analogWrite(LED_TEMPM,138);
      
      //analogWrite(6,LOW);
      digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
        }
        
  Serial.print("Temperature = ");
  Serial.println(event.temperature);
  
  Serial.print("moisture= ");
  Serial.println(moist);
  delay(500);
 
 
  
}

