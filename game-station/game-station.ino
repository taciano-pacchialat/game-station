#include "game-stages.h"

#define DEBUG 1


void setup()
{
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  lcd.init();
  lcd.backlight();
  start_menu(lcd);
  int players = select_players(lcd);
}

void loop()
{

}

