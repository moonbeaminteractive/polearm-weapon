#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9);

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
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(buttonPin, INPUT);
 // Serial.println("Connected!");
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
  if (mySerial.available()){
    incomingByte = mySerial.read();
    mySerial.print("I received: ");
    mySerial.println(incomingByte);
  }

  //send data
  if (buttonRState == HIGH) {
    mySerial.write(RText);
    delay(50);
  }
   if (buttonGState == HIGH) {
    mySerial.write(GText);
    delay(50);
  }
   if (buttonBState == HIGH) {
    mySerial.write(BText);
    delay(50);
  }
}
