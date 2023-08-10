#line 1 "/home/taci/repos/game-station/file-managing.cpp"
#include "file-managing.h"

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

String random_word(File &file, int lines, node **words_used)
{
  if (file)
  {
    String text;
    while (1)
    {
      int i = random(1, lines + 1);
      Serial.print("i = "); // DEBUG
      Serial.println(i);    // DEBUG
      for (int j = 0; j < i; j++)
        text = file.readStringUntil('\n');
      file.seek(0);
      if (!is_included(*words_used, text.c_str()))
      {
        add_first(words_used, text.c_str());
        Serial.print("Word chosen: "); // DEBUG
        Serial.println(text);          // DEBUG
        return text;
      }
    }
  }
  else
    Serial.println("File reading failed");
}
