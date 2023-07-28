#include "charades.h"

// prompts the user to input the amount of seconds each round lasts
unsigned long set_round_duration(LiquidCrystal_I2C &lcd)
{
  lcd.clear();
  lcd.backlight();
  unsigned long seconds = 0;
  lcd.setCursor(0, 0);
  lcd.print("Tiempo:");
  lcd.setCursor(13, 0);
  unsigned int state = 0;
  while (1)
  {
    lcd.print(seconds);
    while (!state)
      state = read_pins();
    if ((1 & state) && (seconds > 5))
      seconds -= 5;
    else if ((2 & state) && (seconds < 994))
      seconds += 5;
    else if (4 & state)
    {
      delay(BUTTON_DELAY);
      return seconds;
    }
    delay(BUTTON_DELAY);
  }
}

// displays a menu before beginning the round.
void player_prepare(LiquidCrystal_I2C &lcd)
{
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("+ para sumar");
  lcd.setCursor(0, 1);
  lcd.print("- para pasar");
  unsigned int state = 0;
  while (1)
  {
    while (!state)
      state = read_pins();
    if (4 & state)
    {
      delay(BUTTON_DELAY);
      return;
    }
  }
}

// chooses a random word of either verbs or nouns.
String choose_word(LiquidCrystal_I2C &lcd, File &nouns, File &verbs, node **words_used)
{
  randomSeed(analogRead(0));
  if (random(1, 500) % 2)
    return random_word(nouns, MAX_NOUNS, words_used);
  else
    return random_word(verbs, MAX_VERBS, words_used);
}

// checks if the user skipped or guessed.
int check_answer()
{
  unsigned int state = 0;
  while (1)
  {
    while (!state)
      state = read_pins();
    if (4 & state)
    {
      delay(BUTTON_DELAY);
      return 1;
    }
    else if (8 & state)
    {
      delay(BUTTON_DELAY);
      return 0;
    }
  }
}

// plays a round until the time limit hasn't been trespassed.
// returns the points obtained by the player.
int play_round(LiquidCrystal_I2C &lcd, unsigned long time, File &nouns, File &verbs)
{
  String current_word;
  unsigned int points = 0;
  time *= 1000; // convert from seconds to milliseconds
  lcd.clear();
  lcd.backlight();
  node *words_used = NULL;             // initialize list
  unsigned long start_time = millis(); // set the starting time of the round
  while (millis() - start_time <= time)
  {
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Palabra:");
    lcd.setCursor(0, 1);
    current_word = choose_word(lcd, nouns, verbs, &words_used);
    lcd.print(current_word);
    points += check_answer();
  }
  return points;
}

// prints in the lcd the points and awaits for -> button.
void print_points(LiquidCrystal_I2C &lcd, int &points)
{
  unsigned int state = 0;
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Se acabo!");
  lcd.setCursor(0, 1);
  lcd.print("Puntaje:");
  lcd.setCursor(10, 1);
  lcd.print(points);
  while (1)
  {
    while (!state)
      state = read_pins();
    if (4 & state)
    {
      delay(BUTTON_DELAY);
      return;
    }
  }
}

// asks the user if he/she wants to play another round
int another_round(LiquidCrystal_I2C &lcd)
{
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Otra?");
  unsigned int state = 0;
  while (1)
  {
    while (!state)
      state = read_pins();
    if (4 & state)
    {
      delay(BUTTON_DELAY);
      return 1;
    }
    else if (8 & state)
    {
      delay(BUTTON_DELAY);
      return 0;
    }
  }
}

// plays an entire game of charades
void charades_game(LiquidCrystal_I2C &lcd)
{
  File nouns;
  initialize_file(nouns, "unrepeated-nouns.txt");
  File verbs;
  initialize_file(verbs, "unrepeated-verbs.txt");
  int points;
  unsigned long time = set_round_duration(lcd);
  while (1)
  {
    points = play_round(lcd, time, nouns, verbs);
    print_points(lcd, points);
    if (another_round(lcd))
      continue;
    else
      break;
  }
}