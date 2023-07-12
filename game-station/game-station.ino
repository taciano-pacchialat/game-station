#include "game-stages.h"

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
  int amount_players = select_players_amount(lcd);
  int amount_spies = select_spy_amount(lcd, amount_players);
  bool *roles = set_spy(amount_players, amount_spies);
  String text = random_noun();
  display_roles(lcd, roles, amount_players, text);
}

void loop()
{

}

