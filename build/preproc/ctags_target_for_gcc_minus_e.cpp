# 1 "/home/taci/repos/game-station/game-station.ino"
# 2 "/home/taci/repos/game-station/game-station.ino" 2
# 3 "/home/taci/repos/game-station/game-station.ino" 2
# 4 "/home/taci/repos/game-station/game-station.ino" 2
# 5 "/home/taci/repos/game-station/game-station.ino" 2
# 6 "/home/taci/repos/game-station/game-station.ino" 2








# 13 "/home/taci/repos/game-station/game-station.ino"
int start_menu(LiquidCrystal_I2C &lcd);
void atReset();

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
File nouns;
File verbs;
int game;

void setup()
{



  lcd.init();
  lcd.clear();
  pinMode(10, 0x1);
  pinMode(7, 0x0);
  pinMode(6, 0x0);
  pinMode(5, 0x0);
  pinMode(4, 0x0);
  initialize_file(nouns, "nouns.txt");
  initialize_file(verbs, "verbs.txt");
  atexit(atReset);
}

void loop()
{
  
# 40 "/home/taci/repos/game-station/game-station.ino" 3
 __asm__ __volatile__ ("wdr")
# 40 "/home/taci/repos/game-station/game-station.ino"
            ;
  game = start_menu(lcd);
  
# 42 "/home/taci/repos/game-station/game-station.ino" 3
 __asm__ __volatile__ ("wdr")
# 42 "/home/taci/repos/game-station/game-station.ino"
            ;
  randomSeed(millis());
  if (game == 1)
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
        delay(500);
        return 0;
      }
      else if (4 & state)
      {
        wdt_enable(9);
        delay(500);
        return 1;
      }
      else if (1 & state) // for resetting
      {
        wdt_enable(
# 82 "/home/taci/repos/game-station/game-station.ino" 3
                  0
# 82 "/home/taci/repos/game-station/game-station.ino"
                           ); // 15ms timeout
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
