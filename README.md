# Stage-with-Arduino
In this project, we try to create the visual effects that we can find on a Festival screen.  For this, we will create different visuals that will change to the rhythm of the music thanks to a microphone. Thanks to this, we will be able to go from static visuals to being in apparent movement, following the rhythm.
// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 32x32 RGB LED matrix:
// http://www.adafruit.com/products/607

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <RGBmatrixPanel.h>


// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

int x = 0;
int y = 0;
int rad = 1;

void setup() {

  pinMode (12, INPUT);

  matrix.begin();
  matrix.setTextSize(3);     // size 1 == 8 pixels high
  matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
 
}

void loop() {

    // Do nothing -- image doesn't change
    matrix.fillScreen(matrix.Color333(0, 0, 0)); // Pantalla en negro
    matrix.drawCircle(x, y, rad, matrix.Color888(random(255), random(255), random(255/rad))); // Hacer circulo con color y cada vez que se va haciendo mas grande, pierde color
    delay(150);
    


      while (!digitalRead(12)) {
      }
    
      matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro
    
      matrix.setTextColor(matrix.Color888(7, 0, 0));
      matrix.print("JJ");
      delay (5);
    
      matrix.drawCircle(0, 0, 31, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 28, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 25, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 20, matrix.Color333(56, random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 15, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 10, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 5, matrix.Color333(random (255), random (255), random (255)));
      delay(5);
      matrix.drawCircle(0, 0, 10, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 15, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 20, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 25, matrix.Color333(56, random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 28, matrix.Color333(random (255), random (255), random(255)));
      delay(5);
      matrix.drawCircle(0, 0, 31, matrix.Color333(random (255), random (255), random(255)));
      delay(5);

      matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro
  matrix.drawRect(0, 0, 32, 32, matrix.Color888(random(255), random(255), random(255)));
  matrix.fillCircle(16, 18, 2, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawLine(16, 16, 16, 8, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawLine(13, 15, 19, 15, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawLine(13, 15, 10, 11, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawLine(19, 15, 22, 11, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawLine(16, 8, 10, 2, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawLine(16, 8, 22, 2, matrix.Color888(random(255), random(255), random(255)));
  delay (50);
  
  while (!digitalRead(12))

  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Pantalla en negro
    matrix.drawCircle(x, y, rad, matrix.Color888(random(255), random(255), random(255/rad))); // Hacer circulo con color y cada vez que se va haciendo mas grande, pierde color
    delay(50);

     matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro
    matrix.drawRect(0, 0, 32, 32, matrix.Color888(random(255), random(255), random(255))); 
    matrix.fillCircle(16, 18, 2, matrix.Color888(random(255), random(255), random(255)));
    matrix.drawLine(16, 16, 16, 8, matrix.Color888(random(255), random(255), random(255)));
    matrix.drawLine(13, 15, 19, 15, matrix.Color888(random(255), random(255), random(255)));
    matrix.drawLine(13, 15, 10, 19, matrix.Color888(random(255), random(255), random(255)));
    matrix.drawLine(19, 15, 22, 19, matrix.Color888(random(255), random(255), random(255)));
    matrix.drawLine(16, 8, 10, 2, matrix.Color888(random(255), random(255), random(255)));
    matrix.drawLine(16, 8, 22, 2, matrix.Color888(random(255), random(255), random(255)));
    delay(50);



    rad++;
    if (rad > 15) {
      x = random(32);
      y = random(32);
      rad = 1;
    }
  }
