#line 1 "/home/taci/repos/game-station/clist.h"
#ifndef CHAR_LIST_INCLUDED
#define CHAR_LIST_INCLUDED

/*
  char * linked list library coded in C for lower memory usage.
  It's implemented to avoid repeating already chosen words.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node
{
  char *data;
  struct node *next;
};

typedef struct node node;

// initializes the list
void initialize_list(node **list);

// adds as first a piece of data
void add_first(node **list, const char *data);

// prints the list in the console
void print_list(node *list);

// adds at the end a char *
void add_last(node **list, const char *data);

// returns the amount of elements the list contains
int list_size(node *list);

// deletes the list from the heap
void delete_list(node **list);

// returns 1 if the element is included, 0 if not.
int is_included(node *list, const char *data);

#endif