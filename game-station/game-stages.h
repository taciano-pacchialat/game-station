#ifndef GAME_STAGES
#define GAME_STAGES

#include <SD.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

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

unsigned int read_pins();
int start_menu(LiquidCrystal_I2C& lcd);
int select_players(LiquidCrystal_I2C& lcd);

#endif