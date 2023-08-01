#line 1 "/home/taci/repos/game-station/charades.h"
#ifndef CHARADES_INCLUDED
#define CHARADES_INCLUDED

/*
  library for charades game
 */

#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "spy.h"

#define MAX_VERBS 1162
#define MAX_NOUNS 1404

void charades_game(LiquidCrystal_I2C &lcd, File &nouns, File &verbs);
unsigned long set_round_duration(LiquidCrystal_I2C &lcd);
#endif