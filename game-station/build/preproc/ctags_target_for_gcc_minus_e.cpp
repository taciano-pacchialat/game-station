# 1 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
# 2 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino" 2

void setup()
{
  Serial.begin(115200);
  pinMode(10, 0x1);
  pinMode(7, 0x0);
  pinMode(6, 0x0);
  pinMode(5, 0x0);
  pinMode(4, 0x0);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setContrast()
  start_menu(lcd);
  int amount_players = select_players_amount(lcd);
  int amount_spies = select_spy_amount(lcd, amount_players);
  bool *roles = set_spy(amount_players, amount_spies);
  String text = random_noun();
  Serial.println(text);
  display_roles(lcd, roles, amount_players, text);
}

void loop()
{

}
