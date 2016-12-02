#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

const int buttonRPin = 2;     // the number of the pushbutton pin
const int buttonGPin = 3;     // the number of the pushbutton pin
const int buttonBPin = 4;     // the number of the pushbutton pin
 
// variables will change:
int buttonRState = 0;   
int buttonGState = 0;   
int buttonBState = 0;   
char RText = "r";
char GText = "g";
char BText = "b";
int incomingByte = 0;

void setup()
{
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(buttonPin, INPUT);
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Serial Connected.");

}

void loop()
{
  buttonRState = digitalRead(buttonRPin);
  buttonGState = digitalRead(buttonGPin);
  buttonBState = digitalRead(buttonBPin);

  //receive data
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

  //send data
  if (buttonRState == HIGH) {
    Serial.write(RText);
    delay(50);
  }
   if (buttonGState == HIGH) {
    Serial.write(GText);
    delay(50);
  }
   if (buttonBState == HIGH) {
    Serial.write(BText);
    delay(50);
  }
}
