#include <stdlib.h>
#include "queue.h"
#include "node.h"

Queue *initQueue(void)
{
	Queue *q = malloc(sizeof(Queue));

	q->head = NULL;
	q->tail = NULL;

	return q;
}

// Insert a new node at the back of the queue (i.e., the tail of the list).
// Return -1 if insertion fails, or 'data' if insertion succeeds. You might
// want to call the createNode() function defined in node.c.
int enqueue(Queue *p, int data)
{
	if (p == NULL)
		return -1;

	else if (p->tail == NULL)
	{
		p->head = p->tail = createNode(data);
		return p->tail->data;
	}
	else
	{
		p->tail->next = createNode(data);
		p->tail = p->tail->next;
		return p->tail->data;
	}
}

// Remove the element at the front of the list (i.e., the head of the list).
// Return the 'data' stored in the dequeued node, or -1 if the queue is empty.
// Keep in mind that you need to free() the node being removed to avoid memory
// leaks.
int dequeue(Queue *p)
{
	int retval;
	node *new_head;

	if (p == NULL || p->head == NULL)
		return -1;

	retval = p->head->data;
	new_head = p->head->next;
	free(p->head);
	p->head = new_head;

	if (p->head == NULL)
		p->tail = NULL;

	return retval;
}

int isEmpty(Queue *p)
{
	return (p->head == NULL);
}
