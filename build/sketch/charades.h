#line 1 "/home/taci/repos/game-station/charades.h"
#ifndef CHARADES_INCLUDED
#define CHARADES_INCLUDED

/*
  library for charades game
 */

#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "spy.h"

void charades_game(LiquidCrystal_I2C &lcd);
unsigned long set_round_duration(LiquidCrystal_I2C &lcd);
#endif