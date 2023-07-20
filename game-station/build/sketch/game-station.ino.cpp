#include <Arduino.h>
#line 1 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
#include "spy.h"
#include "file-managing.h"

#line 4 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
void setup();
#line 19 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
void loop();
#line 4 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
void setup()
{
  Serial.begin(115200);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  pinMode(CS_PIN, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  File nouns;
  File verbs;
  initialize_file(nouns, "nouns.txt");
  initialize_file(verbs, "verbs.txt");
}

void loop()
{

}


