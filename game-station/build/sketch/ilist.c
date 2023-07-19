#line 1 "/home/taci/repos/arduino-for-fun/game-station/ilist.c"
#include <stdlib.h>
#include <stdio.h>
#include "./ilist.h"

/* 
Integer linked list library.
*/

// initializes the list
void initialize_list(node **list)
{
  *list = NULL;
}

// adds a node to the beggining of the list
void add_first(node **list, int data)
{
  node *new_node;
  new_node = (node *)malloc(sizeof(node));
  new_node->next = *list;
  new_node->data = data;
  *list = new_node;
}

// prints the list
void print_list(node *list)
{
  while (list != NULL)
  {
    printf("%d -> ", list->data);
    list = list->next;
  }
  printf("NULL\n");
}

// adds a node to the end of the list
void add_last(node **list, int data)
{
  if (*list == NULL)
    add_first(list, data);
  else
  {
    node *aux;
    aux = *list;
    while (aux->next != NULL)
      aux = aux->next;
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = data;
    aux->next = new_node;
  }
}

// returns the amount of nodes contained in the list
int list_size(node *list)
{
  int size = 0;
  while (list != NULL)
  {
    list = list->next;
    size++;
  }
  return size;
}

// deletes the list from the heap
void delete_list(node **list)
{
  node *aux;
  while (*list != NULL)
  {
    aux = *list;
    *list = (*list)->next;
    free(aux);
  }
}

// 0 if the number is not included 
// 1 if it is
int is_included(node *list, int number)
{
  while ((list->next != NULL) && (list->data != number))
    list = list->next;
  return (list->data == number);
}
