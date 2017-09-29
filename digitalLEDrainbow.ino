
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      144
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second

int redbrightlvl = 225;                  // starting color will be red
int greenbrightlvl = 0;
int bluebrightlvl = 0;
int transition = 1;


void setup() {
  
  // End of trinket special code
  Serial.begin(9600);
  pixels.setBrightness(40);
  pixels.begin(); // This initializes the NeoPixel library.
  for(int i=0; i<144; i++){
       pixels.setPixelColor(i, pixels.Color(0,0,0));
       pixels.show();
  }
  
}

int trailingGreen[150];
int trailingBlue[150];
int trailingRed[150];
int indexBuild = 0;
int setLed =0;


void loop() {
  
      for(int i=indexBuild; i>=0;i--){
        if(i==0){
          trailingGreen[i] = greenbrightlvl;
          trailingRed[i] = redbrightlvl;
          trailingBlue[i] = bluebrightlvl;  
        }
        else{
          trailingGreen[i] = trailingGreen[i-1];
          trailingBlue[i] = trailingBlue[i-1];
          trailingRed[i] = trailingRed[i-1];
        }
      }
      if(indexBuild < 144){
        indexBuild++;
      }

      for(int k=indexBuild; k >=0; k--){
        pixels.setPixelColor(setLed, pixels.Color(trailingRed[k], trailingGreen[k], trailingBlue[k]));
         
        setLed++;
      }
      pixels.show(); 
      setLed = 0;

      
      if (transition == 1) {                                 // Transitions 1 through 10 execute the commands for fading between each color that I considered a "checkpoint" in the rainbow
        redtoorange();
      }
      else if (transition == 2) {
        orangetoyellow();
      }
      else if (transition == 3) {
        yellowtolimegreen();
      }
      else if (transition == 4) {
        limegreentogreen();
      }
      else if (transition == 5) {
        greentoturquoise();
      }
      else if (transition == 6) {
        turquoisetoblue();
      }
      else if (transition == 7) {
        bluetopurpley();
      }
      else if (transition == 8) {
        purpleytopurple();
      }
      else if (transition == 9) {
        purpletopink();
      }
      else if (transition == 10) {
        pinktored();
      }
     
   }





void redtoorange(){                                  //this function changes the brightness level of green so that the color displayed will fade from red to orange. 
  greenbrightlvl += 1;
  if (greenbrightlvl >=79) {
    greenbrightlvl = 80;
    transition = 2;
  }
}

void orangetoyellow(){
  greenbrightlvl += 2;
  if (greenbrightlvl >= 220) {
    greenbrightlvl = 225;
    transition = 3;
  }
}

void yellowtolimegreen(){
  redbrightlvl -= 2;
  if (redbrightlvl <= 130) {
    redbrightlvl = 128;
    transition = 4;
  }
}

void limegreentogreen(){
  redbrightlvl -= 1;
  if (redbrightlvl <=2) {
    redbrightlvl = 0;
    transition = 5;
  }
}

void greentoturquoise(){
  bluebrightlvl += 3;
  if (bluebrightlvl >= 219) {
    bluebrightlvl = 225;
    transition = 6;

  }
}

void turquoisetoblue(){
  greenbrightlvl -= 3;
  if (greenbrightlvl <= 6) {
    greenbrightlvl = 0;
    transition = 7;  
  }
}

void bluetopurpley(){
  redbrightlvl += 1;
  if (redbrightlvl >= 124) {
    redbrightlvl = 127;
    transition = 8;
  }
}

void purpleytopurple(){
  redbrightlvl += 2;
  if (redbrightlvl >=220) {
    redbrightlvl = 225;
    transition = 9;
  }
}

void purpletopink(){
  bluebrightlvl -= 3;
  if (bluebrightlvl <= 84) {
    bluebrightlvl = 80;
    transition = 10;
  }
}


void pinktored(){
  bluebrightlvl -= 1;
  if (bluebrightlvl <= 2) {
    bluebrightlvl = 0;
    transition = 1;
  }
}
