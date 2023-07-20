#ifndef CHAR_LIST_INCLUDED
#define CHAR_LIST_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node 
{
  char *data;
  struct node *next;
};

typedef struct node node;

void initialize_list(node **list);
void add_first(node **list, char *data);
void print_list(node *list);
void add_last(node **list, char *data);
int list_size(node *list);
void delete_list(node **list);
int is_included(node *list, char *data);

#endif