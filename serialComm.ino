const int buttonPin = 2;     // the number of the pushbutton pin
 
// variables will change:
int buttonState = 0;   
char text = "a";

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
    char inChar = Serial.read();
   // inAvailable = true;
  }

  //send data
  if (buttonState == HIGH) {
    Serial.write(text);
    //buttonState = LOW;
    delay(50);
  }
}
