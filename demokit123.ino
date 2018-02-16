#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#define  LED_PIN  13
#define IN_PIN 7
AndroidAccessory acc("Manufacturer",
    "Model",
    "Description",
    "1.0",
    "http://yoursite.com",
                "0000000012345678");
void setup()
{
  // set communiation speed
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  //pinMode(IN_PIN, INPUT);
  acc.powerOn();
}
 
void loop()
{
  byte msg[1];
  byte data[3];
  if (acc.isConnected()) {
    int len = acc.read(msg, sizeof(msg), 1); // read data into msg variable
    if (len > 0) {
      switch (msg[0])
      {
        case 'a':
          digitalWrite(LED_PIN,HIGH);
          break;
        case 0:
          digitalWrite(LED_PIN,LOW);
          break;
      }

    }
   data[0] = 0xc8;
    acc.write(data,1); 
  } 
  else
    digitalWrite(LED_PIN , LOW); // turn off light

   //digitalRead(IN_PIN);
   delay(10);
   
  
}
 
