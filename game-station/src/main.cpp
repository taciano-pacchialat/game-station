#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define LED 13
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 
void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Cagon");
  delay(500);
  lcd.clear();
  delay(500);
}

