#include <LiquidCrystal_I2C.h>
#include "./libraries/palabras/palabras.h"
#include <SD.h>

#define DEBUG 1

#define BOFF 1
#define BON 0
#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10

typedef struct 
{
  int pin1 : 1;
  int pin2 : 1;
  int pin3 : 1;
  int pin4 : 1;
} buttonInputs;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
char **vector;
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  
  

}

void loop()
{
  #if DEBUG 
  String test = palabra_random(vector);
  // lcd.setCursor(0, 0);
  // lcd.print(test);
  delay(3000);
  // lcd.clear();
  #endif
}