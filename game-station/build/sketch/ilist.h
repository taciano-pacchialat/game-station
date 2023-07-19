#line 1 "/home/taci/repos/arduino-for-fun/game-station/ilist.h"
#ifndef INTEGER_LIST
#define INTEGER_LIST


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
int is_included(node *list, int number);

#endif