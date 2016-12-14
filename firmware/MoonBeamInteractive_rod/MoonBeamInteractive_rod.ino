#include <Arduino.h>
#include "Statistic.h"
#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET



/////////// PUSHBUTTONS, LEDS, BUZZERS ///////////

const int buttonPin_green = 9;
const int buttonPin_blue = 6;
const int buttonPin_red = 8;

const int ledPin = 13;

const int buzzerPin = 3;              // buzzer positive pin

//const int testPin = 9;


/////////// ADXL ///////////

Statistic xStats;

// these constants describe the pins. They won't change:
const int ADXL_xpin = A3;                  // x-axis of the accelerometer
const int ADXL_ypin = A2;                  // y-axis
const int ADXL_zpin = A1;                  // z-axis (only on 3-axis models)

#define ADXL_N_VALUES   100               // number of ADXL values for statistics
#define ADXL_STDEV_THRESHOLD  50          // sigma threshold for accelerometer


/////////// DOTSTAR ///////////

#define DOTSTAR_NUMPIXELS  13 // Number of LEDs in strip
#define DOTSTAR_NUMPIXELS_ON  13      // Number of LEDs to be actually used
#define DOTSTAR_NUMPIXELS_MANA  10   // Number of LEDs for Mana

#define DOTSTAR_DELAY_MS  500

#define DOTSTAR_DATAPIN    5
#define DOTSTAR_CLOCKPIN   4

Adafruit_DotStar strip = Adafruit_DotStar(
                           DOTSTAR_NUMPIXELS, DOTSTAR_DATAPIN, DOTSTAR_CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
//Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);


#define DOTSTAR_COLOR_BLUE  0x0000FF
#define DOTSTAR_COLOR_RED  0x00FF00
#define DOTSTAR_COLOR_GREEN  0xFF0000
#define DOTSTAR_COLOR_YELLOW  0xFFFF00
#define DOTSTAR_COLOR_BLANK  0x000000


// SPELLS state
#define NO_SPELL     0  //default
#define SPELL_RED    1  //indices
#define SPELL_GREEN  2
#define SPELL_BLUE   3
int spell_to_apply = 0;

//SPELL DELAY TIMER
#define DEFAULT_BLOCKOUT 2000
#define BOOSTED_BLOCKOUT 10000
unsigned long set_blockout_time;    //TODO: MAKE THIS 20 OR 30 SECONDS LATER. OR MAYBE EVEN A MINUTE

boolean spell_castable = true;
unsigned long blockout_start_time = 0;

//PICKUP PRESENT CHECK
//boolean pickup_present = true;

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
  
 // while (!Serial) {
 //   ; // wait for serial port to connect. Needed for native USB port only
 // }

  // Recharge spells
  // @TODO this info comes from the pickups, through the Vest
  /*spell_count[SPELL_RED] = 3;
  spell_count[SPELL_GREEN] = 3;
  spell_count[SPELL_BLUE] = 3;*/
  set_blockout_time = DEFAULT_BLOCKOUT;

  /////////// PUSHBUTTONS, LEDS, BUZZERS ///////////

  pinMode(buttonPin_green, INPUT);
  pinMode(buttonPin_blue, INPUT);
  pinMode(buttonPin_red, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  //pinMode(testPin, OUTPUT);
  //digitalWrite(testPin, HIGH);

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

 ///////// RECEIVE PICKUP FROM VEST ////////
//   if (Serial.available()){
  //  incomingArray = Serial.read();
    // if (incomingArray == 'r') { //this can be anything coming from the vest
     // Serial.print("I received: ");
     // Serial.println(incomingByte);
     // spell_delayed = 1; //now the spell is recharged
    // }
    //setBlockoutTime(pickup_bit_bool);
 // }


  /////////// PUSHBUTTONS ///////////


  int button_reading_green = digitalRead(buttonPin_green);
  int button_reading_blue = digitalRead(buttonPin_blue);
  int button_reading_red = digitalRead(buttonPin_red);


  if (button_reading_red) {
    spell_to_apply = SPELL_RED;
    //tone(5,10000);
  }
  else if (button_reading_green) {
    spell_to_apply = SPELL_GREEN;
    //tone(5,5000);
  }
  else if (button_reading_blue) {
    spell_to_apply = SPELL_BLUE;
    //tone(5,50000);
  }
  else
  {
    spell_to_apply = NO_SPELL;
    //noTone(5);
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

  ///////////Setting delay timer for each spell//////////////
  //set the boolean to true if millis are crossed, and you can stop incrementing them?
  if(millis()-blockout_start_time > set_blockout_time)
  {
      spell_castable = true;
  }
  

  /////////// BUZZER ///////////

  //put all this inside an "if spell is castable".
    if(spell_castable)
    {
        if (stdev > ADXL_STDEV_THRESHOLD && spell_to_apply != NO_SPELL) // if wand was moved rapidly and some spell button is pressed
        {   
            castSpell(spell_to_apply);
            spell_castable = false;
            blockout_start_time = millis();

        }



      /////////// DOTSTAR ///////////

        if (button_reading_red) {
          //if (spell_count[spell_to_apply] > 0) { // if we have enough spells left
            for (int i = 0; i < DOTSTAR_NUMPIXELS; ++i) {
              strip.setPixelColor(i, DOTSTAR_COLOR_RED); // Dotstar: red
            }
            strip.show();
            delay(DOTSTAR_DELAY_MS);
          //}
        }
      
        if (button_reading_blue) {
          //if (spell_count[spell_to_apply] > 0) { // if we have enough spells left
            for (int i = 0; i < DOTSTAR_NUMPIXELS; ++i) {
              strip.setPixelColor(i, DOTSTAR_COLOR_BLUE); // blue
            }
            strip.show();
            delay(DOTSTAR_DELAY_MS);
         // }
        }
        
        if (button_reading_green) {
          //if (spell_count[spell_to_apply] > 0) { // if we have enough spells left
            for (int i = 0; i < DOTSTAR_NUMPIXELS; ++i) {
              strip.setPixelColor(i, DOTSTAR_COLOR_GREEN); // green
            }
            strip.show();
            delay(DOTSTAR_DELAY_MS);
          //}
        }
    


      for (int i = 0; i < DOTSTAR_NUMPIXELS; ++i) {
        strip.setPixelColor(i, DOTSTAR_COLOR_YELLOW); // yellow
      }
      strip.show();

    }

}




////////// function for updating blockout times, based on pickup information //////////
void setBlockoutTime(boolean pickup_present)
{
    if(pickup_present)
    {
        set_blockout_time = BOOSTED_BLOCKOUT;
    }
    else
    {
        set_blockout_time = DEFAULT_BLOCKOUT;
    }
}




/////////// BUZZER ///////////
void buzz(int ms) {
  digitalWrite(buzzerPin, HIGH);
  delay(ms);
  digitalWrite(buzzerPin, LOW);
  delay(ms);
}

/////////CAST SPELL//////

void castSpell(int req_spell_to_apply)    // apply spell
{
   for (int i = 0; i < 4; ++i) 
   {       
      buzz(100 * (req_spell_to_apply));  // red spell buzzer period: 100ms, green spell buzzer period: 200ms, blue spell buzzer period
      
   }
   //spell_count[spell_to_apply]--;      // reduce number of times to apply spell
   //Serial.println("***************************SPELL CAST!");
   //start delay timer again from 0
}




/////////// DOTSTAR ///////////
void DOTSTAR_INIT() {
  for (int i = 0; i < DOTSTAR_NUMPIXELS_MANA; ++i) {
    strip.setPixelColor(i, DOTSTAR_COLOR_YELLOW);
    strip.show();
    delay(100);
  }
  for (int i = DOTSTAR_NUMPIXELS_MANA; i < DOTSTAR_NUMPIXELS; ++i) {
    strip.setPixelColor(i, DOTSTAR_COLOR_BLANK);
  }

  strip.show();

}




