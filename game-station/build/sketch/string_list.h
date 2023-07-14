#line 1 "/home/taci/repos/arduino-for-fun/game-station/string_list.h"
#ifndef STRING_LIST
#define STRING_LIST

/* 
  linked list of strings.
  Implemented in C for higher performance.
 */

struct node 
{
  struct node* next;
  String data;
}

typedef struct node node;

// returns a pointer to NULL
node *initialize_list();

// adds an element at the beggining of the list
void add_first(String data, node **list);

// adds an element at the end of the list
void add_last(String data, node **list);

// returns the amount of elements inside the list
int list_size(node *list);

// checks if data is contained in the list
bool contains(String data, node *list);

// frees the entire list
void delete_list(node **list);

#endif