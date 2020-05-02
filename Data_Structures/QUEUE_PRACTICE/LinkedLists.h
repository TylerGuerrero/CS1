#ifndef __LINKEDLISTS_H
#define __LINKEDLISTS_H

#define EMPTY_QUEUE_ERR INT_MIN

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct LinkedList
{
  node *head;
  node *tail;
} LinkedList;

LinkedList *create_list(void);

LinkedList *destroy_list(LinkedList *list);

void tail_insert(LinkedList *list, int data);

int head_delete(LinkedList *list);

#endif
