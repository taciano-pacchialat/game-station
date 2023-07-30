#line 1 "/home/taci/repos/game-station/spy.h"
#ifndef GAME_STAGES
#define GAME_STAGES

#include <LiquidCrystal_I2C.h>
#include <SD.h>
#include <SPI.h>
#include <Arduino.h>
#include "file-managing.h"

#define BOFF 1
#define BON 0
#define BUTTON1 7
#define BUTTON2 6
#define BUTTON3 5
#define BUTTON4 4
#define BUTTON_DELAY 500
#define MAX_NOUNS 1404

int spy_game(LiquidCrystal_I2C &lcd);
unsigned int read_pins();

#endif