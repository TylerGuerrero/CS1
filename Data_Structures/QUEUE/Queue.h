#ifndef __QUEUE_H
#define __QUEUE_H

// Queue.h
// =======
// Header file for linked list-based implementation of queues. Includes
// struct definitions and functional prototypes.

#define EMPTY_QUEUE_ERR INT_MIN

typedef struct Queue
{
  LinkedList *list;
  int size;
} Queue;

// Functional prototypes.

Queue *create_queue(void);

int isEmpty(Queue *q);

int isFull(Queue *q);

void enqueue(Queue *q, int data);

int dequeue(Queue *q);

int peek(Queue *q);

int front(Queue *q);

#endif
