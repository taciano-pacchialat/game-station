#include "file-managing.h"

void initialize_file(File& file, String name)
{
  SD.begin(CS_PIN);
  if (!SD.begin(CS_PIN))
  {
    Serial.print("Failed initializing SD\n");
    while(1);
  }
  file = SD.open(name, FILE_READ);
  if (!file)
  {
    Serial.print("File opening failed!\n"); 
    while (1);
  }
}

