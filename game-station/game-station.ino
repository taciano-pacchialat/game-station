#include "game-stages.h"

#define DEBUG 0


void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  lcd.init();
  lcd.backlight();
  start_menu(lcd);
  int amount_players = select_players(lcd);
  bool *roles = set_spy(amount_players);
  
}

void loop()
{

}

