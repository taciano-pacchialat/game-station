#include "spy.h"
#include "file-managing.h"


//TODO make ilist a char * linked list

void setup()
{
  Serial.begin(115200);
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  pinMode(CS_PIN, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  File nouns;
  File verbs;
  initialize_file(nouns, "nouns.txt");
  initialize_file(verbs, "verbs.txt");
}

void loop()
{

}

