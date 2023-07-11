#ifndef GAME_STAGES
#define GAME_STAGES

#include <SD.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <string.h>

#define BOFF 1
#define BON 0
#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10
#define SPI_PIN 1
#define WORDS_IN_FILE 1204

unsigned int read_pins();
int start_menu(LiquidCrystal_I2C& lcd);
int select_players_amount(LiquidCrystal_I2C& lcd);
int select_spy_amount(LiquidCrystal_I2C& lcd, int amount_players);
bool *set_spy(int amount_players, int amount_spies);
void display_roles(LiquidCrystal_I2C& lcd, bool *roles, int amount_players, String text);
String random_noun();

#endif