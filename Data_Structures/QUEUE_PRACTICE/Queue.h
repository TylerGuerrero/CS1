#ifndef __QUEUE_H
#define __QUEUE_H

#define EMPTY_QUEUE_ERR INT_MIN

typedef struct Queue
{
  LinkedList *list;
  int size;
} Queue;

Queue *create_queue(void);

int isEmpty(Queue *q);

int isFull(Queue *q);

void enqueue(Queue *q, int data);

void destroy_queue(Queue *q);

int dequeue(Queue *q);

int peek(Queue *q);

int front(Queue *q);

#endif
