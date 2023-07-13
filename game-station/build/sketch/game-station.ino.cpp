#include <Arduino.h>
#line 1 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
#include "game-stages.h"

#line 3 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
void setup();
#line 25 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
void loop();
#line 3 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
void setup()
{
  Serial.begin(115200);
  pinMode(CS_PIN, OUTPUT);
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
  Serial.print("Spy amount: ");
  Serial.println(amount_spies);
  bool *roles = set_spy(amount_players, amount_spies);
  String text = random_noun();
  Serial.println(text);
  display_roles(lcd, roles, amount_players, text);
}

void loop()
{

}


