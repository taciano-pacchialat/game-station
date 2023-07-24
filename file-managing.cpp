#include "file-managing.h"

// initializes a file called "name"
void initialize_file(File& file, const String name)
{
  if (!SD.begin(CS_PIN))
  {
    Serial.print("Failed initializing SD card\n");
    while (1);
  }
  file = SD.open(name, FILE_READ);
  if (!file)
  {
    Serial.print("File opening failed!\n"); 
    while (1);
  }
}

// returns a random word from the file
String random_word(File& file, node **words_used)
{
  if (file)
  {
    String text;
    while (1)
    {
      randomSeed(analogRead(0));
      int i = random(1, WORDS_IN_FILE + 1);
      for (int j = 0; j < i; j++)
        text = file.readStringUntil('\n');
      if (!is_included(*words_used, text.c_str()))
      {
        add_first(words_used, text.c_str());
        return text;
      }
    }
  }
  else
    Serial.println("File reading failed");
  file.close();
}


