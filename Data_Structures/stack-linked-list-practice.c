#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define EMPTY_STACK_ERR INT_MIN
#define MAX_RAND_VAL 1000

// Stacks are LIFO structures (last in, first out), and they support the following operations:

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

Stack *createStack(void)
{
  Stack *s = malloc(sizeof(Stack));
  s->head = NULL;
  s->size = 0;

  return s;
}

node *create_node(int data)
{
  node *new_node = malloc(sizeof(node));
  new_node->next = NULL;
  new_node->data = data;
  return new_node;
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

int isEmpty(Stack *s)
{
  return (s == NULL || s->head == NULL || s->size == 0);
}

int isFull(Stack *s)
{
  return 0;
}

void push(Stack *s, int data)
{
  node *new_head;

  if (s == NULL)
    return;

  else if (s->head == NULL)
  {
    new_head = create_node(data);
    s->head = new_head;
    s->size++;
    return;
  }
  else
  {
    new_head = create_node(data);
    new_head->next = s->head;
    s->head = new_head;
    s->size++;
  }
}

int pop(Stack *s)
{
  int retval;
  node *temp;

  if (isEmpty(s))
    return EMPTY_STACK_ERR;

  retval = s->head->data;
  temp = s->head->next;
  free(s->head);
  s->head = temp;
  s->size--;

  return retval;
}
int peek(Stack *s)
{
  if (isEmpty(s))
    return EMPTY_STACK_ERR;

  return s->head->data;
}

int front(Stack *s)
{
  return peek(s);
}

void print_stack(Stack *s)
{
  node *current;
  int i;

  if (isEmpty(s))
    return;

  i = s->size - 1;
  for (current = s->head; current != NULL && i >= 0; current = current->next)
  {
    printf("+--------+\n");
    printf("|  %-4d  |%s\n", current->data,
    (i == s->size - 1) ? " <- Top of the Stack" : "");
    printf("+--------+\n");
    i--;
  }
  printf("\n\n");

}

int *create_array_with_nums(int n)
{
  int i;
  int *array = malloc(sizeof(int) * n);
  srand(time(NULL));

  for (i = 0; i < n; i++)
    array[i] = rand() % MAX_RAND_VAL + 1;

  return array;
}

int main(void)
{
  int i, n = 12;
  int *array = create_array_with_nums(n);
  Stack *s = createStack();
  int p;

  for (i = 0; i < n; i++)
    push(s, array[i]);

  p = peek(s);
  printf("%d\n\n", p);

  print_stack(s);

  while(!isEmpty(s))
    printf("Popping %d\n", pop(s));

  s = destroyStack(s);
  free(array);


  return 0;
}
