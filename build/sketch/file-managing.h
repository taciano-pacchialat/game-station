#line 1 "/home/taci/repos/game-station/file-managing.h"
#ifndef FILE_MANAGING_INCLUDED
#define FILE_MANAGING_INCLUDED

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

extern "C"
{
#include "clist.h"
};

#define CS_PIN 10

/*
  Library used for properly working with files located in the SD card.
*/

// looks for the file inside the SD.
void initialize_file(File &file, const String &name);

// Returns a random word from the file which is not present on the list, and adds it
// at the end of it.
String random_word(File &file, int lines, node **list);

#endif