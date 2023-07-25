#line 1 "/home/taci/repos/game-station/charades.cpp"
#include "charades.h"

// prompts the user to input the amount of seconds each round lasts
unsigned long set_round_duration(LiquidCrystal_I2C &lcd)
{
  lcd.clear();
  lcd.backlight();
  unsigned long seconds = 0;
  lcd.setCursor(0, 0);
  lcd.print("Tiempo:");
  lcd.setCursor(13, 0);
  unsigned int state = 0;
  while (1)
  {
    lcd.print(seconds);
    while (!state)
      state = read_pins();
    if ((1 & state) && (seconds > 5))
      seconds -= 5;
    else if ((2 & state) && (seconds < 994))
      seconds += 5;
    else if (4 & state)
    {
      delay(BUTTON_DELAY);
      return seconds;
    }
    delay(BUTTON_DELAY);
  }
}

void player_prepare(LiquidCrystal_I2C &lcd)
{
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("+ para sumar");
  lcd.setCursor(0, 1);
  lcd.print("- para pasar");
  unsigned int state = 0;
  while (1)
  {
    while (!state)
      state = read_pins();
    if (4 & state)
    {
      delay(BUTTON_DELAY);
      return;
    }
  }
}

int play_round(unsigned long time)
{
  String current_word;
  unsigned int points = 0;
  time *= 1000; // convert from seconds to milliseconds
  unsigned long start_time = millis();
  while (millis() - start_time <= time)
  {
    randomSeed(analogRead(0));
    }
}

// plays an entire game of charades
void charades_game(LiquidCrystal_I2C &lcd)
{
}