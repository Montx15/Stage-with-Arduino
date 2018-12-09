#include <RGBmatrixPanel.h>
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

int frame = 0;
unsigned long t = 0;

void setup() {
  // put your setup code here, to run once:
  matrix.begin();
  pinMode (12, INPUT);
  Serial.begin(9600);
  frame0();
}

void loop() {
  // put your main code here, to run repeatedly:

  while (!digitalRead(12)) {
    if (millis() - t >= 500 && frame != 0) {
      frame = 0;
      frame0();
    }
  }

  frame = frame + 1;
  if (frame >= 4) {
    frame = 1;
  }

  if (frame == 0)
    frame0();
  else if (frame == 1)
    frame1();
  else if (frame == 2)
    frame2();
  else if (frame == 3)
    frame3();

  t = millis();

  Serial.println(frame);

  delay(300);


}

void frame0() {
  matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro
  matrix.drawRect(0, 0, 32, 32, matrix.Color888(random(255), random(255), random(255)));
  matrix.drawRect(2, 2, 28, 28, matrix.Color888(random(255), random(255), random(255)));
  matrix.fillCircle(16, 18, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 16, 16, 8, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 19, 15, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 10, 11, matrix.Color888(255, 255, 255));
  matrix.drawLine(19, 15, 22, 11, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 8, 10, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 8, 22, 2, matrix.Color888(255, 255, 255));
}

void frame1() {

  matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro

  matrix.drawLine(31, 23, 31, 31, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(31, 31, 0, 31, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(0, 31, 0, 23, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(31, 0, 31, 20, matrix.Color888(255, 255, 0));
  matrix.drawLine(32, 0, 0, 0, matrix.Color888(255, 255, 0));
  matrix.drawLine(0, 0, 0, 20, matrix.Color888(255, 255, 0));
  matrix.drawLine(29, 2, 29, 15, matrix.Color888(255, 255, 255));
  matrix.drawLine(25, 2, 6, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(2, 2, 2, 15, matrix.Color888(255, 255, 255));
  matrix.drawLine(27, 2, 27, 10, matrix.Color888(255, 255, 0));
  matrix.drawLine(4, 2, 4, 10, matrix.Color888(255, 255, 0));

  matrix.begin();
  matrix.setCursor(2, 2);
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color888(255, 255, 0));
  matrix.setRotation(2);
  matrix.println("DANCE");
  matrix.setRotation(0);
  matrix.fillCircle(16, 18, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 16, 16, 8, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 19, 15, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 10, 19, matrix.Color888(255, 255, 255));
  matrix.drawLine(19, 15, 22, 19, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 8, 10, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 8, 22, 2, matrix.Color888(255, 255, 255));
}
void frame2() {

  matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro

  matrix.drawLine(31, 23, 31, 31, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(31, 31, 0, 31, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(0, 31, 0, 23, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(31, 0, 31, 20, matrix.Color888(0, 0, 255));
  matrix.drawLine(32, 0, 0, 0, matrix.Color888(0, 0, 255));
  matrix.drawLine(0, 0, 0, 20, matrix.Color888(0, 0, 255));
  matrix.drawLine(29, 2, 29, 15, matrix.Color888(67, 227, 246));
  matrix.drawLine(25, 2, 6, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(2, 2, 2, 15, matrix.Color888(67, 227, 246));
  matrix.drawLine(27, 2, 27, 10, matrix.Color888(255, 255, 0));
  matrix.drawLine(4, 2, 4, 10, matrix.Color888(255, 255, 0));

  matrix.begin();
  matrix.setCursor(2, 2);
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color888(255, 255, 0));
  matrix.setRotation(2);
  matrix.println("YEAH!");
  matrix.setRotation(0);
  matrix.fillCircle(16, 18, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 16, 16, 8, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 19, 15, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 16, 11, matrix.Color888(255, 0, 255));
  matrix.drawLine(19, 15, 22, 11, matrix.Color888(255, 0, 255));
  matrix.drawLine(16, 8, 10, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 8, 22, 2, matrix.Color888(255, 255, 255));
}

void frame3() {

  matrix.fillScreen(matrix.Color888(0, 0, 0)); // Pantalla en negro

  matrix.drawLine(31, 23, 31, 31, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(31, 31, 0, 31, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(0, 31, 0, 23, matrix.Color888(random(0), random(255), random(255)));
  matrix.drawLine(31, 0, 31, 20, matrix.Color888(255, 0, 0));
  matrix.drawLine(32, 0, 0, 0, matrix.Color888(255, 0, 0));
  matrix.drawLine(0, 0, 0, 20, matrix.Color888(255, 0, 0));
  matrix.drawLine(29, 2, 29, 15, matrix.Color888(246, 67, 135));
  matrix.drawLine(25, 2, 6, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(2, 2, 2, 15, matrix.Color888(246, 67, 135));
  matrix.drawLine(27, 2, 27, 10, matrix.Color888(255, 255, 0));
  matrix.drawLine(4, 2, 4, 10, matrix.Color888(255, 255, 0));

  matrix.begin();
  matrix.setCursor(2, 2);
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color888(255, 255, 0));
  matrix.setRotation(2);
  matrix.println("SHAKE");
  matrix.setRotation(0);
  matrix.fillCircle(16, 18, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 16, 16, 8, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 19, 15, matrix.Color888(255, 255, 255));
  matrix.drawLine(13, 15, 10, 11, matrix.Color888(255, 0, 255));
  matrix.drawLine(19, 15, 16, 11, matrix.Color888(255, 0, 255));
  matrix.drawLine(16, 8, 10, 2, matrix.Color888(255, 255, 255));
  matrix.drawLine(16, 8, 22, 2, matrix.Color888(255, 255, 255));
}
