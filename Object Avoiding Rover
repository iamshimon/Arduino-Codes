# Robotics


const int trig=13;
const int echo=12;


const int ma1=11;
const int ma2=10;
const int mb1=9;
const int mb2=8;
const int en1=7;
const int en2=6;
const int svcc=5;
long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT);
pinMode(svcc,OUTPUT);
digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
digitalWrite(svcc,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echo,HIGH);
  distance=duration/29/2;

  moveforward();
  if (distance < 5 )  {
    moveright();
    delay(100);
     } 
    
  }
  void movebackward()
       {
        
        digitalWrite(ma1,1);
        digitalWrite(ma2,0);
        digitalWrite(mb1,1);
        digitalWrite(mb2,0);
       }

  void moveforward()
      {
        digitalWrite(ma1,0);
        digitalWrite(ma2,1);
        digitalWrite(mb1,0);
        digitalWrite(mb2,1);
    
       }

  void moveleft()
       {
        digitalWrite(ma1,HIGH);
        digitalWrite(ma2,0);
        digitalWrite(mb1,0);
        digitalWrite(mb2,1);
       
       }

   void moveright()
       {
        digitalWrite(ma1,LOW);
        digitalWrite(ma2,HIGH);
        digitalWrite(mb1,HIGH);
        digitalWrite(mb2,LOW);
       }

   
