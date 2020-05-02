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
  node *ptr = malloc(sizeof(node));

  if (ptr == NULL)
  {
    printf("Could not allocate memory\n");
    return NULL;
  }

  ptr->data = data;
  ptr->next = NULL;

  return ptr;
}

node *tail_insert(node *head, int data)
{
  node *temp;

  if (head == NULL)
    return create_node(data);

  for (temp = head; temp->next != NULL; temp = temp->next)
    ;

  temp->next = create_node(data);

  return head;
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
node *tail_insert_alternative(node *head, int data)
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
    printf("%d%c", temp->data, (temp->next == NULL) ? '\n' : ' ');

}

void print_list_alternative(node *head)
{
  if (head == NULL)
  {
    printf("Empty List\n");
    return;
  }

  for (head = head; head != NULL; head = head->next)
    printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');

}

void print_list_fancy(node *head)
{
  for ( ; ; )
  {
    if (head == NULL)
      break;

    printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
    head = head->next;
  }
}

void print_list_recrusive_helper(node *head)
{
  if (head == NULL)
    return;

  printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
  print_list_recrusive_helper(head->next);
}

void print_list_recrusive(node *head)
{
  if (head == NULL)
  {
    printf("Empty List\n");
    return;
  }

  print_list_recrusive_helper(head);
}

node *deleteNth(node *head, int n)
{
  int i;
  node *current, *temp;

  if (head == NULL)
    return NULL;

  i = 0;
  current = head;
  while (current->next != NULL && i < n - 1)
  {
    current = current->next;
    i++;
  }

  if (current != NULL)
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
  node *current;

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
  node *current, *sorted_node;

  if (head == NULL || n < head->data)
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
  int i, r;
  node* head;

  head = NULL;

  srand(time(NULL));

  for (i = 0; i < 10; i++)
  {
    printf("Inserting %d...\n", r = rand() % 100 + 1);
    head = tail_insert(head, r);
  }

  print_list(head);
  print_list_alternative(head);
  print_list_fancy(head);
  print_list_recrusive(head);

  return 0;
}
