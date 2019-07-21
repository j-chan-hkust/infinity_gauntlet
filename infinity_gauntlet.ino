#include <softwareserial.h>
#include <dfplayer_mini_mp3.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN    6 //todo subject to change
#define NEOPIXEL_COUNT 6 //todo subject to change currently i have one for each infinity stone 

Adafruit_NeoPixel strip(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800); // NEO_GRB and NEO_KHZ800 are part of the neopixel library i guess

#define FLEXSENSOR_PIN 5 //todo redefine later

int previousTime;
int currTime;
int voltage;
int previous_voltage;
int voltage_derivative;
int baseline_voltage

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //this sets up serial connection, so we can do shit
  
  // establish connection with DF player mini
  mp3_set_serial (Serial); //set Serial for DFPlayer-mini mp3 module  
  mp3_set_volume (10);

  // correct set up for the neopixels
  strip.begin();
  strip.show(); 

  int sum = 0;
  for(int k = 0; i<3; i++){  
    for(int i = 0; i<6; i++){
      sum += analogRead(FLEXSENSOR_PIN)
      for(int j = 0; i<6; i++){
        if(i==j)
          strip.setPixelColor(i, 255, 255, 255);
        else 
          strip.setPixelColor(i, 0, 0, 0);
      }
      delay(10) 
    }
  }
  baseline = sum/18
}


void loop() {
  // put your main code here, to run repeatedly:
  
  previousTime = currTime;                                           // Save the time of the previous cycle
  currTime = millis();
  float interval = time - previousTime;                      // Calculate the time it takes to run a cycle

  voltage = analogRead(FLEXSENSOR_PIN);
  voltage_derivative =  ( voltage - previous_voltage ) / interval; // now we have a derivative

  //breathing

  //if derivative is high enough
  //play sound, change the light animation
  //when animation finishes, go back to breathing

  //can check when sound is done using readstate()

  
  
  mp3_play (1); // input range is 0-9999, will search the sd card for a file that starts with that number.

  
}


#define BREATHING_SPEED 15
//this function exists because i suck lol
void breathing(bool dontBreathe, int interval = 0){
  if (dontBreathe)
    return;
  

  if(interval<15)
    return;
  
  
}
