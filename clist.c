#include "./clist.h"

void initialize_list(node **list)
{
  *list = 0;
}

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

void print_list(node *list)
{
  while (list != 0)
  {
    printf("%s -> ", list->data);
    list = list->next;
  }
  printf("0\n");
}

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

int is_included(node *list, const char *data)
{
  while (list->next != 0)
  {
    if (strcmp(list->data, data) == 0)
      return 1;
    list = list->next;
  }
  return 0;
}
