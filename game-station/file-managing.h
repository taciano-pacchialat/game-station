#ifndef FILE_MANAGING_INCLUDED
#define FILE_MANAGING_INCLUDED

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

#define CS_PIN 10

void initialize_file(File& file, String name);


#endif