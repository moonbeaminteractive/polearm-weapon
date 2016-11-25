#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (7, 8);
byte addresses[][6] = {"0"};
const int buttonPin = 9;  

int buttonState = 0;

struct package
{
  int id=1;
  char  text[100] = "Text to be transmitted";
};


typedef struct package Package;
Package data;


void setup()
{
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
  delay(1000);
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe( addresses[0]);
  delay(1000);
}

void loop()
{
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH) {
    myRadio.write(&data, sizeof(data)); 
    Serial.print("\nPackage:");
    Serial.print(data.id);
    Serial.print("\n");
    Serial.println(data.text);
    data.id = data.id + 1;
    delay(1000);
  } else {
    Serial.println("no data");
  }
 

}
