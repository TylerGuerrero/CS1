// Queue.c
// =======
// Linked list-based implementation of queues.

// enqueue()  -  add an element to the back of the queue
// dequeue()  -  remove an element from the front of the queue
// isEmpty()  -  returns true if the queue is empty, false otherwise
// isFull()  -  returns true if the queue is full, false otherwise
// front(), peek()  -  returns the value at the front of the queue without dequeuing it

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedLists.h"
#include "Queue.h"

Queue *create_queue(void)
{
  Queue *q = malloc(sizeof(Queue));
  q->list = create_list();
  q->size = 0;

  return q;
}

void destroy_queue(Queue *q)
{
  if (q == NULL)
    return;

  destroy_list(q->list);
  free(q);

}

int isEmpty(Queue *q)
{
  return (q == NULL || q->list == NULL || q->size == 0);
}

int isFull(Queue *q)
{
  return 0;
}

void enqueue(Queue *q, int data)
{
  if (q == NULL || q->list == NULL)
    return;

  q->size++;
  tail_insert(q->list, data);

}

int dequeue(Queue *q)
{
  if (isEmpty(q))
    return EMPTY_QUEUE_ERR;

  q->size--;
  return head_delete(q->list);
}

int peek(Queue *q)
{
  if (isEmpty(q))
    return EMPTY_QUEUE_ERR;

  return q->list->head->data;
}

int front(Queue *q)
{
  return peek(q);
}

// Just a trivial test of the queue's functionality.
int main(void)
{
	int i, r, n = 100;
	Queue *q = create_queue();

	srand(time(NULL));

	// Enqueue a few elements.
	for (i = 0; i < n; i++)
	{
		printf("Enqueueing %d...\n", r = rand() % 100 + 1);
		enqueue(q, r);
	}

	// Empty out the queue.
	while (!isEmpty(q))
		printf("%d\n", dequeue(q));

	// Exercise: Write this function yourself.
	 destroy_queue(q);

	return 0;
}
