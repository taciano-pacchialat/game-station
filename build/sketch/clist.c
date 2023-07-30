#line 1 "/home/taci/repos/game-station/clist.c"
#include "./clist.h"

/*
char *linked list library.
*/

// initializes the list
void initialize_list(node **list)
{
  *list = 0;
}

// adds a node to the beginning of the list
void add_first(node **list, const char *data)
{
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node != 0)
  {
    new_node->next = *list;
    new_node->data = strdup(data); // Duplicate the input string to store in the node
    *list = new_node;
  }
}

// prints the list
void print_list(node *list)
{
  while (list != 0)
  {
    printf("%s -> ", list->data);
    list = list->next;
  }
  printf("0\n");
}

// adds a node to the end of the list
void add_last(node **list, const char *data)
{
  if (*list == 0)
    add_first(list, data);
  else
  {
    node *aux = *list;
    while (aux->next != 0)
      aux = aux->next;
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == 0)
    {
      perror("Memory allocation error");
      exit(EXIT_FAILURE);
    }
    new_node->next = 0;
    new_node->data = strdup(data); // Duplicate the input string to store in the node
    aux->next = new_node;
  }
}

// returns the amount of nodes contained in the list
int list_size(node *list)
{
  int size = 0;
  while (list != 0)
  {
    list = list->next;
    size++;
  }
  return size;
}

// deletes the list from the heap
void delete_list(node **list)
{
  while (*list != 0)
  {
    node *aux = *list;
    *list = (*list)->next;
    free(aux->data); // Free the memory used by the string
    free(aux);
  }
}

// 0 if the data is not included
// 1 if it is
int is_included(node *list, const char *data)
{
  while (list != 0)
  {
    if (strcmp(list->data, data) == 0)
      return 1;
    list = list->next;
  }
  return 0;
}
