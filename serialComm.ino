const int buttonPin = 2;     // the number of the pushbutton pin
 
// variables will change:
int buttonState = 0;   
char text = "a";
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
  if (buttonState == HIGH) {
    Serial.write(text);
    delay(50);
  }
}
