#include "spy.h"
#include "charades.h"
#include "file-managing.h"
#include <LiquidCrystal_I2C.h>

#define CHARADES 1
#define SPY 0
#define LCDPROP 0x27, 16, 2

int start_menu(LiquidCrystal_I2C &lcd)
{
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("<- Espia");
  lcd.setCursor(0, 1);
  lcd.print("-> Digalo ...");
  unsigned int state = 0;
  while (1)
  {
    state = read_pins();
    if (state)
    {
      if (8 & state)
        return SPY;
      else if (4 & state)
        return CHARADES;
    }
  }
}

void setup()
{
  Serial.begin(115200);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  lcd.init();
  lcd.clear();
  pinMode(CS_PIN, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  int game;
  while (1)
  {
    game = start_menu(lcd);
    randomSeed(millis());
    if (game == CHARADES)
      charades_game(lcd);
    else
      spy_game(lcd);
  }
}

void loop()
{
}