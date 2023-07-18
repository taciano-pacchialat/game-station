#line 1 "/home/taci/repos/arduino-for-fun/game-station/spy.h"
#ifndef GAME_STAGES
#define GAME_STAGES

#include <LiquidCrystal_I2C.h>
#include <SD.h>
#include <SPI.h>
#include <Arduino.h>
#include "ilist.h"

#define BOFF 1
#define BON 0
#define BUTTON1 7
#define BUTTON2 6
#define BUTTON3 5
#define BUTTON4 4
#define CS_PIN 10
#define WORDS_IN_FILE 2353


int spy_game(LiquidCrystal_I2C& lcd);

#endif