#ifndef GAME_STAGES
#define GAME_STAGES

#include <SD.h>
#include <LiquidCrystal_I2C.h>
#include <time.h>
#include <stdlib.h>
#include <Arduino.h>

#define BOFF 1
#define BON 0
#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10

unsigned int read_pins();
int start_menu(LiquidCrystal_I2C& lcd);
int select_players(LiquidCrystal_I2C& lcd);

#endif