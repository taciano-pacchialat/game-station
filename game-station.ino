#include "spy.h"
#include "charades.h"
#include "file-managing.h"
#include <LiquidCrystal_I2C.h>
#include <avr/wdt.h>

#define CHARADES 1
#define SPY 0
#define LCDPROP 0x27, 16, 2

#define DEBUG 0

int start_menu(LiquidCrystal_I2C &lcd);
void atReset();

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
File nouns;
File verbs;
int game;

void setup()
{
#if DEBUG
  Serial.begin(115200);
#endif
  lcd.init();
  lcd.clear();
  pinMode(CS_PIN, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  initialize_file(nouns, "nouns.txt");
  initialize_file(verbs, "verbs.txt");
  atexit(atReset);
}

void loop()
{
  wdt_reset();
  game = start_menu(lcd);
  wdt_reset();
  randomSeed(millis());
  if (game == CHARADES)
    charades_game(lcd, nouns, verbs);
  else
    spy_game(lcd, nouns);
  lcd.clear();
  lcd.backlight();
}

// function for choosing between charades or spy game
int start_menu(LiquidCrystal_I2C &lcd)
{
  wdt_enable(9); // set a reset in 8 seconds
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("<- Espia");
  lcd.setCursor(0, 1);
  lcd.print("-> Digalo");
  unsigned int state = 0;
  wdt_disable();
  while (1)
  {
    state = read_pins();
    if (state)
    {
      if (8 & state)
      {
        wdt_enable(9);
        delay(BUTTON_DELAY);
        return SPY;
      }
      else if (4 & state)
      {
        wdt_enable(9);
        delay(BUTTON_DELAY);
        return CHARADES;
      }
      else if (1 & state) // for resetting
      {
        wdt_enable(WDTO_15MS); // 15ms timeout
        while (1)
          ;
      }
    }
  }
}

void atReset()
{
  nouns.close();
  verbs.close();
}