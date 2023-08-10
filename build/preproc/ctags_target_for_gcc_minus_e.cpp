# 1 "/home/taci/repos/game-station/game-station.ino"
# 2 "/home/taci/repos/game-station/game-station.ino" 2
# 3 "/home/taci/repos/game-station/game-station.ino" 2
# 4 "/home/taci/repos/game-station/game-station.ino" 2
# 5 "/home/taci/repos/game-station/game-station.ino" 2





// function for choosing between charades or spy game
int start_menu(LiquidCrystal_I2C &lcd)
{
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("<- Espia");
  lcd.setCursor(0, 1);
  lcd.print("-> Digalo");
  unsigned int state = 0;
  while (1)
  {
    state = read_pins();
    if (state)
    {
      if (8 & state)
      {
        delay(500);
        return 0;
      }
      else if (4 & state)
      {
        delay(500);
        return 1;
      }
    }
  }
}

void setup()
{
  Serial.begin(115200);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  lcd.init();
  lcd.clear();
  pinMode(10, 0x1);
  pinMode(7, 0x0);
  pinMode(6, 0x0);
  pinMode(5, 0x0);
  pinMode(4, 0x0);
  int game;
  File nouns;
  initialize_file(nouns, "nouns.txt");
  File verbs;
  initialize_file(verbs, "verbs.txt");
  while (1)
  {
    game = start_menu(lcd);
    randomSeed(millis());
    if (game == 1)
      charades_game(lcd, nouns, verbs);
    else
      spy_game(lcd, nouns);
    lcd.clear();
    lcd.backlight();
  }
  nouns.close();
  verbs.close();
}

void loop()
{
}
