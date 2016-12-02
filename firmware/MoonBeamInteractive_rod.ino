#include <Arduino.h>
#include "Statistic.h"
#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET



/////////// PUSHBUTTONS, LEDS, BUZZERS ///////////

const int buttonPin_green = 2;
const int buttonPin_blue = 3;
const int buttonPin_red = 4;

const int ledPin = 13;

const int buzzerPin = 5;              // buzer positive pin


/////////// ADXL ///////////

Statistic xStats;

// these constants describe the pins. They won't change:
const int ADXL_xpin = A3;                  // x-axis of the accelerometer
const int ADXL_ypin = A2;                  // y-axis
const int ADXL_zpin = A1;                  // z-axis (only on 3-axis models)

#define ADXL_N_VALUES   100               // number of ADXL values for statistics
#define ADXL_STDEV_THRESHOLD  25          // sigma threshold for accelerometer


/////////// DOTSTAR ///////////

#define DOTSTAR_NUMPIXELS  13 // Number of LEDs in strip
#define DOTSTAR_NUMPIXELS_ON  13      // Number of LEDs to be actually used
#define DOTSTAR_NUMPIXELS_MANA  10   // Number of LEDs for Mana

#define DOTSTAR_DATAPIN    6
#define DOTSTAR_CLOCKPIN   7

Adafruit_DotStar strip = Adafruit_DotStar(
                           DOTSTAR_NUMPIXELS, DOTSTAR_DATAPIN, DOTSTAR_CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
//Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);


#define DOTSTAR_COLOR_BLUE  0xFF0000
#define DOTSTAR_COLOR_RED  0x00FF00
#define DOTSTAR_COLOR_GREEN  0x0000FF
#define DOTSTAR_COLOR_YELLOW  0xFFFF00
#define DOTSTAR_COLOR_BLANK  0x000000


                           
void setup() {
  // initialize the serial communications:
  Serial.begin(9600);


  /////////// PUSHBUTTONS, LEDS, BUZZERS ///////////

  pinMode(buttonPin_green, INPUT);
  pinMode(buttonPin_blue, INPUT);
  pinMode(buttonPin_red, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);


  /////////// ADXL ///////////
  xStats.clear(); //explicitly start clean

  /////////// DOTSTAR ///////////

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif

  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP


  DOTSTAR_INIT();

}








void loop() {

/////////// PUSHBUTTONS ///////////


  int button_reading_green = digitalRead(buttonPin_green);
  int button_reading_blue = digitalRead(buttonPin_blue);
  int button_reading_red = digitalRead(buttonPin_red);

  if(button_reading_green && button_reading_blue && button_reading_red) {
      digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }


/////////// ADXL ///////////

  int xval, yval, zval, stdev;

  for (int i = 0; i < ADXL_N_VALUES; ++i) {
    xval = analogRead(ADXL_xpin);
    yval = analogRead(ADXL_ypin);
    zval = analogRead(ADXL_zpin);

    // delay before next reading:
    //delay(10);

    xStats.add(xval);

  }

  stdev = xStats.unbiased_stdev();
  Serial.print(stdev);
  Serial.println();

  xStats.clear();

/////////// BUZZER ///////////

  if(stdev > ADXL_STDEV_THRESHOLD) {
    for(int i = 0; i < 5; ++i) {
      buzz();
    }
  }
  


/////////// DOTSTAR /////////// 


  
  if(button_reading_red) {
    DOTSTAR_FLASH(DOTSTAR_COLOR_RED);
  }

  if(button_reading_blue) {
    DOTSTAR_FLASH(DOTSTAR_COLOR_BLUE);
  }
  
  if(button_reading_green) {
    DOTSTAR_FLASH(DOTSTAR_COLOR_GREEN);
  }

  



}









/////////// BUZZER ///////////
void buzz() {
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  delay(100);
}





/////////// DOTSTAR /////////// 
void DOTSTAR_INIT() {
    for (int i = 0; i < DOTSTAR_NUMPIXELS_MANA; ++i) {
    strip.setPixelColor(i, DOTSTAR_COLOR_YELLOW);
    strip.show();
    delay(100);
  }
  for(int i = DOTSTAR_NUMPIXELS_MANA; i < DOTSTAR_NUMPIXELS; ++i) {
    strip.setPixelColor(i, DOTSTAR_COLOR_BLANK);
  }
  
  strip.show();

}

void DOTSTAR_FLASH(int color) {
  for (int i = 0; i < DOTSTAR_NUMPIXELS; ++i) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  delay(100);
  
  for (int i = 0; i < DOTSTAR_NUMPIXELS; ++i) {
    strip.setPixelColor(i, DOTSTAR_COLOR_BLANK);
  }
  strip.show();
  delay(100);
  
// millis()

}

