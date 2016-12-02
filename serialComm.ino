const int buttonPin = 2;     // the number of the pushbutton pin
 
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
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

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
