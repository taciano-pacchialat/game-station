#ifndef CHARADES_INCLUDED
#define CHARADES_INCLUDED

/*
  Library for charades game.
 */

#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "spy.h"

#define MAX_VERBS 1162
#define MAX_NOUNS 1404

// plays an entire game of charades.
void charades_game(LiquidCrystal_I2C &lcd, File &nouns, File &verbs);

#endif