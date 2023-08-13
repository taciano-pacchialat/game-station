#include "spy.h"

unsigned int read_pins()
{
  unsigned int state = 0;
  state |= (!(digitalRead(BUTTON1)) << 3);
  state |= (!(digitalRead(BUTTON2)) << 2);
  state |= (!(digitalRead(BUTTON3)) << 1);
  state |= (!(digitalRead(BUTTON4)) << 0);
  return state;
}

void print_amount(LiquidCrystal_I2C &lcd, int amount)
{
  lcd.setCursor(14, 0);
  lcd.print(amount);
}

// where the amount of players is selected
// returns the amount of players
// returns 0 when there was an error
int select_players_amount(LiquidCrystal_I2C &lcd)
{
  int players = 2;
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jugadores:");
  unsigned int state;
  while (1)
  {
    print_amount(lcd, players);
    state = read_pins();
    while (!state)
      state = read_pins();
    if (state)
    {
      if (2 & state)
        players += 1;
      else if ((1 & state) && (players > 2))
        players -= 1;
      else if (4 & state)
      {
        delay(BUTTON_DELAY);
        return players;
      }
    }
    delay(BUTTON_DELAY);
  }
  return 0;
}

// menu for setting the amount of spies
// and returns it
int select_spy_amount(LiquidCrystal_I2C &lcd, int amount_players)
{
  int spies = 1;
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Espias:");
  unsigned int state;
  while (1)
  {
    lcd.setCursor(14, 0);
    lcd.print(spies);
    state = read_pins();
    while (!state)
      state = read_pins();
    if ((2 & state) && (spies < amount_players))
      spies += 1;
    else if ((1 & state) && (spies > 1))
      spies -= 1;
    else if (4 & state)
    {
      delay(BUTTON_DELAY);
      return spies;
    }
    delay(BUTTON_DELAY);
  }
  return 0;
}

void print_bool_array(bool *arg, int dim)
{
  int i;
  for (i = 0; i < dim; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    if (arg[i])
      Serial.print("Spy\n");
    else
      Serial.print("Not Spy\n");
  }
  Serial.println();
}

// creates an array of bools, each representing
// a player. True if spy, false if not
bool *set_spy(int amount_players, int amount_spies)
{
  randomSeed(millis());
  bool *roles = (bool *)malloc(amount_players * (sizeof(bool)));
  int i;
  for (i = 0; i < amount_players; i++)
    roles[i] = false;
  i = 0;
  while (i < amount_spies)
  {
    int pos = random(0, amount_players);
    if (!roles[pos])
    {
      roles[pos] = true;
      i++;
    }
  }
  return roles;
}

void print_tag(LiquidCrystal_I2C &lcd, int position)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jugador: ");
  lcd.setCursor(11, 0);
  lcd.print(position + 1);
  lcd.setCursor(0, 1);
}

void print_role(LiquidCrystal_I2C &lcd, bool role, String palabra)
{
  if (role)
    lcd.print("Espia");
  else
    lcd.print(palabra);
}

// displays roles of current round
void display_roles(LiquidCrystal_I2C &lcd, bool *roles, int amount_players, String text)
{
  int i = 0;
  unsigned int state;
  bool tag_displayed = false;
  lcd.backlight();
  while (i < amount_players)
  {
    state = read_pins();
    while (!state)
      state = read_pins();

    if (4 & state)
    {
      if (tag_displayed)
      {
        print_role(lcd, roles[i], text);
        i++;
        tag_displayed = false;
      }
      else
      {
        print_tag(lcd, i);
        tag_displayed = true;
      }
    }
    else if ((8 & state) && (i > 0))
    {
      tag_displayed = false;
      lcd.clear();
      if (!tag_displayed && (i > 1))
        i -= 2;
      else
        i--;
    }
    delay(BUTTON_DELAY);
  }
  delay(BUTTON_DELAY);
}

// displays the end screen for a round
int end_screen(LiquidCrystal_I2C &lcd)
{
  delay(BUTTON_DELAY);
  lcd.clear();
  lcd.backlight();
  lcd.print("Otra?");
  lcd.setCursor(12, 1);
  lcd.print(":-)");
  unsigned int state;
  state = read_pins();
  while (1)
  {
    while (!state)
      state = read_pins();
    if (state & 8)
    {
      delay(BUTTON_DELAY);
      return 0;
    }
    else if (state & 4)
    {
      delay(BUTTON_DELAY);
      return 1;
    }
  }
}

int spy_game(LiquidCrystal_I2C &lcd, File &nouns)
{
  lcd.init();
  lcd.backlight();
  node *words_used = NULL;
  String current_word;
  unsigned int state;
  int amount_players = select_players_amount(lcd);
  int amount_spies = select_spy_amount(lcd, amount_players);
  randomSeed(millis());
  while (1)
  {
    lcd.clear();
    lcd.backlight();
    bool *roles = set_spy(amount_players, amount_spies);
    String text = random_word(nouns, MAX_NOUNS, &words_used);
    display_roles(lcd, roles, amount_players, text);
    if (end_screen(lcd))
      continue;
    else
    {
      free(roles);
      break;
    }
  }
  delete_list(&words_used);
  return 0;
}