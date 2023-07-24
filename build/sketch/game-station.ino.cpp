#include <Arduino.h>
#line 1 "/home/taci/repos/game-station/game-station.ino"
#include "spy.h"
#include "file-managing.h"

#define CHARADES 1
#define SPY 0

#line 7 "/home/taci/repos/game-station/game-station.ino"
int start_menu(LiquidCrystal_l2C &lcd);
#line 12 "/home/taci/repos/game-station/game-station.ino"
void setup();
#line 24 "/home/taci/repos/game-station/game-station.ino"
void loop();
#line 7 "/home/taci/repos/game-station/game-station.ino"
int start_menu(LiquidCrystal_l2C &lcd)
{
  lcd.backlight();
}

void setup()
{
  Serial.begin(115200);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  pinMode(CS_PIN, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  int game = start_menu(lcd);
}

void loop()
{
}

