# 1 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino"
# 2 "/home/taci/repos/arduino-for-fun/game-station/game-station.ino" 2

void setup()
{
  Serial.begin(115200);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  pinMode(10, 0x1);
  pinMode(7, 0x0);
  pinMode(6, 0x0);
  pinMode(5, 0x0);
  pinMode(4, 0x0);
  spy_game(lcd);
}

void loop()
{

}
