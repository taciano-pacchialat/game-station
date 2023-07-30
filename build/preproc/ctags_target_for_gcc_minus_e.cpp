# 1 "/home/taci/repos/game-station/game-station.ino"
# 2 "/home/taci/repos/game-station/game-station.ino" 2
# 3 "/home/taci/repos/game-station/game-station.ino" 2
# 4 "/home/taci/repos/game-station/game-station.ino" 2
# 5 "/home/taci/repos/game-station/game-station.ino" 2





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
        return 0;
      else if (4 & state)
        return 1;
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
  while (1)
  {
    game = start_menu(lcd);
    randomSeed(millis());
    if (game == 1)
      charades_game(lcd);
    else
      spy_game(lcd);
  }
}

void loop()
{
}
