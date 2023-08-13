#ifndef GAME_STAGES
#define GAME_STAGES

/*
  Library for playing the spy game. The functions which prototypes have
  been declared here are the public ones.
*/

#include <LiquidCrystal_I2C.h>
#include <SD.h>
#include <SPI.h>
#include <Arduino.h>
#include "file-managing.h"
#include <avr/wdt.h>

#define BOFF 1
#define BON 0
#define BUTTON1 7
#define BUTTON2 6
#define BUTTON3 5
#define BUTTON4 4
#define BUTTON_DELAY 500
#define MAX_NOUNS 1404

// returns a binary with the states of the bits
// if the the button is activated, the position = 1
unsigned int read_pins();

// plays a game of spy.
int spy_game(LiquidCrystal_I2C &lcd, File &nouns);

#endif