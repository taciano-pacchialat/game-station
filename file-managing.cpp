#include "file-managing.h"

// initializes a file called "name"
void initialize_file(File &file, const String &name)
{
  if (!SD.begin(CS_PIN))
  {
    Serial.print("Failed initializing SD card\n");
    while (1)
      ;
  }
  file = SD.open(name, FILE_READ);
  if (!file)
  {
    Serial.print("Failed opening: ");
    Serial.println(name);
    while (1)
      ;
  }
}

// Returns a random word from the file which is not present on the list, and adds it
// at the end.
String random_word(File &file, int lines, node **words_used)
{
  if (file)
  {
    String text;
    while (1)
    {
      int i = random(1, lines + 1);
      Serial.print("i = ");
      Serial.println(i);
      for (int j = 0; j < i; j++)
        text = file.readStringUntil('\n');
      if (!is_included(*words_used, text.c_str()))
      {
        Serial.println("Es con add first"); // DEBUG
        add_first(words_used, text.c_str());
        return text;
      }
    }
  }
  else
    Serial.println("File reading failed");
}
