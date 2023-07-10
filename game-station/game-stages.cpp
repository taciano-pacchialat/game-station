#include "game-stages.h"

#define LCDPROP 0x27, 16, 2

// returns a binary with the states of the bits
// if the the button is activated, the position = 1
unsigned int read_pins()
{
  unsigned int state = 0;
  state |= (!(digitalRead(BUTTON1)) << 3);
  state |= (!(digitalRead(BUTTON2)) << 2);
  state |= (!(digitalRead(BUTTON3)) << 1);
  state |= (!(digitalRead(BUTTON4)) << 0);
  #if DEBUG
    Serial.begin(9600);
    Serial.println(state);
  #endif
  return state;
}

// sends start message to lcd
// reads pins
int start_menu(LiquidCrystal_I2C& lcd)
{
  lcd.setCursor(0, 0);
  lcd.print("Presionar");
  lcd.setCursor(0, 1);
  lcd.print("cualquier boton");
  unsigned int state;
  while (1)
  {
    state = read_pins();
    if (state)
    {
      lcd.clear();
      delay(200);
      return 0;
    }
  }
}

void print_amount(LiquidCrystal_I2C& lcd, int amount)
{
  lcd.setCursor(14, 0);
  lcd.print(amount);
}

// where the amount of players is selected
// returns the amount of players
// returns 0 when there was an error
int select_players_amount(LiquidCrystal_I2C& lcd)
{
  int players = 2;
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
        return players;
    }
    delay(300);
  }
  return 0;
}

// menu for setting the amount of spies
// and returns it
int select_spy_amount(LiquidCrystal_I2C& lcd, int amount_players)
{
  int spies = 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Espias:");
  unsigned int state;
  while (1)
  {
    print_amount(lcd, spies);
    state = read_pins();
    while (!state)
      state = read_pins();    
    if (state)
    {
      if ((2 & state) && (spies < amount_players))
        spies += 1;
      else if ((1 & state) && (spies > 1))
        spies -= 1;
      else if (4 & state)
        return spies;
    }
    delay(300);
  }
  return 0;
}

// creates an array of bools, each representing
// a player. True if spy, false if not
bool *set_spy(int amount_players, int amount_spies)
{
  bool *roles = malloc(amount_players * (sizeof(bool)));
  int i;
  for (i = 0; i < amount_players; i++)
    roles[i] = false;
  randomSeed(analogRead(0));

  for (i = 0; i < amount_spies; i++)
  {
    int pos = random(0, amount_players + 1);
    if (!roles[pos])
      roles[pos] = true;
  }
  return roles;
}

void print_tag(LiquidCrystal_I2C& lcd, int position)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jugador: ");
  lcd.setCursor(11, 0);
  lcd.print(position);
  lcd.setCursor(0, 1);
}

void print_role(LiquidCrystal_I2C& lcd, bool role, char *palabra)
{
  if (role)
    lcd.print("Espia");
  else
    lcd.print(palabra);
}

void display_roles(LiquidCrystal_I2C lcd, bool *roles, int amount_players, char *text)
{
  int i = 0;
  unsigned int state;
  bool tag_displayed = false;
  bool undo = false;
  while (1)
  {
    state = read_pins();
    while (!state)
      state = read_pins();

    if ((4 & state) || undo)
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
    else if (8 & state)
    {
      undo = true;
      lcd.clear();
      i--;
    }
  delay(300);
  }

}