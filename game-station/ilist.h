#ifndef INTEGER_LIST
#define INTEGER_LIST

#include <Arduino.h>

struct node 
{
  int data;
  struct node *next;
};

typedef struct node node;

void initialize_list(node **list);
void add_first(node **list, int data);
void print_list(node *list);
void add_last(node **list, int data);
int list_size(node *list);
void delete_list(node **list);
bool is_included(node *list, int number);

#endif