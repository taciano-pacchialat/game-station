#line 1 "/home/taci/repos/arduino-for-fun/game-station/string_list.cpp"
#include "string_list.h"

struct node 
{
  struct node* next;
  String data;
}

typedef struct node node;

node *initialize_list()
{
  node *new_list = NULL;
  return new_list;
}

void add_first(String data, node **list)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *list;
  *list = new_node;
}

void add_last(String data, node **list)
{
  if (*list == NULL)
    add_first(data, list);
  else
    node *aux;
    aux = *list;
    while (aux->next != NULL)
      aux = aux->next;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    node->next = aux->next;
    aux->next = node;
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

bool contains(String data, node *list)
{
  while (list->next != NULL)
  {
    if (list->data == data)
      return true;
    list = list->next;
  }
  return false;
}

void delete_list(node **list)
{
  node *aux;
  while (*list != NULL)
  {
    aux = *list;
    list = (*list)->next;
    free(aux);
  }
}