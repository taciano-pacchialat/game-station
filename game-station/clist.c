#include "./clist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char *linked list library.
*/

// initializes the list
void initialize_list(node **list)
{
    *list = NULL;
}

// adds a node to the beginning of the list
void add_first(node **list, char *data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    new_node->next = *list;
    new_node->data = strdup(data); // Duplicate the input string to store in the node
    *list = new_node;
}

// prints the list
void print_list(node *list)
{
    while (list != NULL)
    {
        printf("%s -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// adds a node to the end of the list
void add_last(node **list, char *data)
{
    if (*list == NULL)
        add_first(list, data);
    else
    {
        node *aux = *list;
        while (aux->next != NULL)
            aux = aux->next;
        node *new_node = (node *)malloc(sizeof(node));
        if (new_node == NULL)
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        new_node->next = NULL;
        new_node->data = strdup(data); // Duplicate the input string to store in the node
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
    while (*list != NULL)
    {
        node *aux = *list;
        *list = (*list)->next;
        free(aux->data); // Free the memory used by the string
        free(aux);
    }
}

// 0 if the data is not included
// 1 if it is
int is_included(node *list, char *data)
{
    while (list != NULL)
    {
        if (strcmp(list->data, data) == 0)
            return 1;
        list = list->next;
    }
    return 0;
}
