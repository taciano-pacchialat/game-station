#line 1 "/home/taci/repos/arduino-for-fun/game-station/ilist.c"
#include <stdlib.h>
#include <stdio.h>
#include "./ilist.h"

void initialize_list(node **list)
{
  *list = NULL;
}

void add_first(node **list, int data)
{
  node *new_node;
  new_node = (node *)malloc(sizeof(node));
  new_node->next = *list;
  new_node->data = data;
  *list = new_node;
}

void print_list(node *list)
{
  while (list != NULL)
  {
    printf("%d -> ", list->data);
    list = list->next;
  }
  printf("NULL\n");
}

// **list es el node
// *list es el puntero
void add_last(node **list, int data)
{
  if (*list == NULL)
    add_first(list, data);
  else
  {
    node *aux;
    aux = *list;
    while (aux->next != NULL)
    {
      printf("data: %d\n", aux->data);
      aux = aux->next;
    }
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = data;
    aux->next = new_node;
  }
}

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

bool is_included(node *list, int number)
{
  while ((list->next != NULL) && (list->data != number))
    list = list->next;
  return (list->data == number);
}
