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

void print_amount(LiquidCrystal_I2C& lcd, int players)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jugadores: ");
  lcd.setCursor(11, 0);
  lcd.print(players);
}

// where the amount of players is selected
// returns the amount of players
// returns 0 when there was an error
int select_players(LiquidCrystal_I2C& lcd)
{
  int players = 2;
  lcd.setCursor(0, 0);
  lcd.print("Jugadores:");
  lcd.setCursor(10, 0);
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

// creates an array of bools, each representing
// a player. True if spy, false if not
bool *set_spy(int amount_players)
{
  bool *roles = malloc(amount_players * (sizeof(bool)));
  int i;
  for (i = 0; i < amount_players; i++)
    roles[i] = false;
  randomSeed(analogRead(0));
  int pos = random(0, amount_players + 1);
  roles[pos] = true;
  return roles;
}