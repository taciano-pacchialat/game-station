#line 1 "/home/taci/repos/arduino-for-fun/game-station/file-managing.h"
#ifndef FILE_MANAGING_INCLUDED
#define FILE_MANAGING_INCLUDED

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

extern "C" {
  #include "clist.h"
};

#define WORDS_IN_FILE 1204
#define CS_PIN 10

void initialize_file(File& file, const String name);
String random_word(File& file, node **list);


#endif