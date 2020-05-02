#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define EMPTY_STACK_ERR INT_MIN


// Stacks are LIFO structures (last in, first out), and they support the following operations:
//
// push()  -  push element onto the top of the stack
// pop()  -  removes the top item from the stack and returns its value
// isEmpty()  -  returns true of the stack is empty, false otherwise
// isFull()  -  returns true if the stack is full, false otherwise
// top(), peek()  -  returns the value at the top of the stack without popping it

// Bottom of the stack is the end of the linked list (push from the head)
// Top of the stack is the head of the linked list (pop from the head)

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct Stack
{
  node *head;
  int size;
} Stack;

Stack *createStack()
{
  Stack *s = malloc(sizeof(Stack));
  if (s == NULL)
  {
    printf("Can not allocate memory\n");
    return NULL;
  }

  s->head = NULL;
  s->size = 0;

  return s;
}

node *destroy_linked_list(node *head)
{
  if (head == NULL)
    return NULL;

  destroy_linked_list(head->next);
  free(head);

  return NULL;
}

Stack *destroyStack(Stack *s)
{
  if (s == NULL)
    return NULL;

  destroy_linked_list(s->head);
  free(s);

  return NULL;
}

node *create_node(int data)
{
  node *new_node = malloc(sizeof(node));
  if (new_node == NULL)
  {
    printf("Could not allocate memory\n");
    return NULL;
  }

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

int isEmpty(Stack *s)
{
  return (s == NULL || s->head == NULL ||  s->size == 0);
}

// Head insert.
void push(Stack *s, int data)
{
  node *new_head;

  if (isEmpty(s))
    return;

  new_head = create_node(data);
  new_head->next = s->head;
  s->head = new_head;
  s->size++;
}

// Head delete.
int pop(Stack *s)
{
  int retval;
  node *new_head;

  if (isEmpty(s))
    return EMPTY_STACK_ERR;

  retval= s->head->data;

  new_head = s->head->next;
  free(s->head);
  s->head = new_head;
  s->size--;

  return retval;
}

int peek(Stack *s)
{
  if (isEmpty(s))
    return EMPTY_STACK_ERR;

  return s->head->data;
}

void print_stack(Stack *s)
{
  node *current;

  if (isEmpty(s))
    return;

  for (current = s->head; current != NULL; current = current->next)
  {
    printf("+--------+\n");
    printf("|  %-4d  |\n", current->data);
    printf("+--------+\n");
  }

}

int main(void)
{
  return 0;
}
