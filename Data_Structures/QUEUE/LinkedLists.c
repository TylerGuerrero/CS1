#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedLists.h"

node *create_node(int data)
{
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

LinkedList *create_list(void)
{
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;

  return list;
}

node *recursive_destroyer(node *head)
{
  if (head == NULL)
    return NULL;

  recursive_destroyer(head->next);
  free(head);

  return NULL;
}

LinkedList *destroy_list(LinkedList *list)
{
  if (list == NULL)
    return NULL;

  recursive_destroyer(list->head);
  free(list);

  return NULL;
}

void tail_insert(LinkedList *list, int data)
{
  if (list == NULL)
    return;
  else if (list->tail == NULL)
    list->head = list->tail = create_node(data);
  else
  {
    list->tail->next = create_node(data);
    list->tail = list->tail->next;
  }
}

int head_delete(LinkedList *list)
{
  int retval;
  node *temp;

  if (list == NULL || list->head == NULL)
    return EMPTY_QUEUE_ERR;

  retval = list->head->data;

  temp = list->head->next;
  free(list->head);
  list->head = temp;

  if (list->head == NULL)
    list->tail = NULL;

  return retval;
}
