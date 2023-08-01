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

int spy_game(LiquidCrystal_I2C &lcd, File &nouns);
unsigned int read_pins();

#endif