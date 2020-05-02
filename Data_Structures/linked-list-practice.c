#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

node *create_node(int data)
{
  node *new_node;

  new_node = malloc(sizeof(node));
  if (new_node == NULL)
  {
    printf("Memory was not allocated\n");
    return NULL;
  }

  new_node->data = data;
  new_node->next = NULL;

  return new_node;

}

node *destroy_linked_list(node *head)
{
  node *temp, *current;

  if (head == NULL)
    return NULL;

  current = head;
  while (current != NULL)
  {
    temp = current->next;
    free(current);
    current = temp;
  }

  return NULL;

}

node *recursive_destroy_linked_list(node *head)
{
  if (head == NULL)
    return NULL;

  recursive_destroy_linked_list(head->next);
  printf("Deleting the node with the value...%d\n", head->data);
  free(head);

  return NULL;
}

node *tail_insert(node *head ,int data)
{
  node *temp;

  if (head == NULL)
    return create_node(data);

  for (temp = head; temp->next != NULL; temp = temp->next)
    ;

  temp->next = create_node(data);
  return head;

}

node *alternative_tail_insert(node *head, int data)
{
  node *temp;

  if (head == NULL)
    return create_node(data);

  temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = create_node(data);
  return head;

}

void print_list(node *head)
{
  node *temp;

  if (head == NULL)
  {
    printf("Empty List\n");
    return;
  }

  for (temp = head; temp != NULL; temp = temp->next)
    printf("%d%c", temp->data, (temp->next != NULL) ? ' ' : '\n');

}

void print_list_alternative(node *head)
{
  if (head == NULL)
    return;

  for (head = head; head != NULL; head = head->next)
    printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');

}

void reverse_print_list_helper(node *head)
{
  if (head == NULL)
    return;

  reverse_print_list_helper(head->next);
  printf("%d ", head->data);
}

void recursive_print_list_helper(node *head)
{
  if (head == NULL)
    return;

  printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
  recursive_print_list_helper(head->next);

}

void recursive_print_list(node *head)
{
  if (head == NULL)
  {
    printf("Empty List\n");
    return;
  }

  recursive_print_list(head);

}

void headInsert(node **head, int data)
{
  node *new_head;

  if (head == NULL)
    return;

  new_head = create_node(data);
  new_head->next = *head;
  *head = new_head;

}

void reverse_print_list(node *head)
{
  if (head == NULL)
  {
    printf("Empty List\n");
    return;
  }

  reverse_print_list_helper(head);
  printf("\n");

}

void print_list_fancy(node *head)
{
  if (head == NULL)
    return;

  for ( ; ; )
  {
    if (head == NULL)
      break;

    printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
    head = head->next;
  }
}


node *alternative_recursive_destroy_linked_list(node *head)
{
  node *temp;

  if (head == NULL)
    return NULL;

  temp = head->next;
  free(head);
  return alternative_recursive_destroy_linked_list(temp);

}

node *recursive_tail_insert(node *head, int data)
{
  if (head == NULL)
    return create_node(data);

  head->next = recursive_tail_insert(head->next, data);
  return head;

}

node *fast_tail_insert(node *tail, int data)
{
  if (tail == NULL)
    return create_node(data);

  tail->next = create_node(data);
  tail = tail->next;
  return tail;

}

node *head_insert(node *head, int data)
{
  node *new_head;

  if (head == NULL)
    return create_node(data);

  new_head = create_node(data);
  new_head->next = head;
  head = new_head;

  return head;

}

node *deleteNth(node *head, int n)
{
  node *current, *temp;
  int i;

  if (head == NULL)
    return NULL;

  current = head;
  i = 0;

  while (current->next != NULL && i < n - 1)
  {
    current = current->next;
    i++;
  }

  if (current->next == NULL)
  {
    printf("You have gone past the list\n");
    return head;
  }

  temp = current->next->next;
  free(current->next);
  current->next = temp;

  return head;

}

node *deleteNthRecursive(node *head, int n)
{
  node *current, *temp;

  if (head == NULL || n < 0)
    return NULL;

  if (n == 0)
  {
    current = head->next;
    free(head);
    return current;
  }

  head->next = deleteNthRecursive(head->next, n - 1);
  return head;

}

node *deleteAlt(node *head)
{
  node *current, *next;

  if (head == NULL)
    return NULL;

  current = head;
  next = head->next;

  while (current != NULL && next != NULL)
  {
    current->next = next->next;
    free(next);
    current = current->next;

    if (current != NULL)
      next = current->next;
  }

  return head;
}

node *deleteAltRecursive(node *head)
{
  node *next;

  if (head == NULL || head->next == NULL)
    return NULL;

  next = head->next;
  head->next = next->next;
  free(next);

  head->next = deleteAltRecursive(head->next);
  return head;

}

node *insertSortedNode(node *head, int n)
{
  node *current, *sorted_node, *temp;

  if (head == NULL)
    return NULL;

  if (head == NULL || head->data < n)
    return head_insert(head, n);

  current = head;
  while (current->next != NULL && current->next->data < n)
    current = current->next;

  sorted_node = create_node(n);
  sorted_node->next = current->next;
  current->next = sorted_node;

  return head;
}

int main(void)
{
  return 0;
}
