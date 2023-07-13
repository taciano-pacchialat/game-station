#line 1 "/home/taci/repos/arduino-for-fun/game-station/game-stages.h"
#ifndef GAME_STAGES
#define GAME_STAGES

#include <LiquidCrystal_I2C.h>
#include <SD.h>
#include <SPI.h>
#include <Arduino.h>

#define BOFF 1
#define BON 0
#define BUTTON1 7
#define BUTTON2 6
#define BUTTON3 5
#define BUTTON4 4
#define CS_PIN 10
#define WORDS_IN_FILE 2353

unsigned int read_pins();
int start_menu(LiquidCrystal_I2C& lcd);
int select_players_amount(LiquidCrystal_I2C& lcd);
int select_spy_amount(LiquidCrystal_I2C& lcd, int amount_players);
bool *set_spy(int amount_players, int amount_spies);
void display_roles(LiquidCrystal_I2C& lcd, bool *roles, int amount_players, String text);
String random_noun();

#endif