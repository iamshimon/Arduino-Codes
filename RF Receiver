#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
void setup()
{
  pinMode(13,OUTPUT);
Serial.begin(9600);
Serial.println("Device is ready");
// Initialize the IO and ISR
vw_setup(2000); // Bits per sec
vw_rx_start(); // Start the receiver
}
void loop()
{
if (vw_get_message(message, &messageLength)) // Non-blocking
{
Serial.print("Received: ");

Serial.write(message[0]);
if (message[0]=='a')
  {
    digitalWrite(13,HIGH);
    delay(2000);
    digitalWrite(13,LOW);
    delay(3000);
    }

}
}
