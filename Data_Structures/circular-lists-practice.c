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
  node *new_node = calloc(1, sizeof(node));
  new_node->data = data;
  return new_node;
}

node *ouroboros_head_insert(node *head, node *tail, int data)
{
  node *new_head = create_node(data);

  if (head == NULL)
  {
    new_head->next = head;
    return new_head;
  }

  new_head->next = head;
  tail->next = new_head;
  return new_head;
}

void ouroboros_head_insert_fancy(node **head, node **tail, int data)
{
  node *new_node = create_node(data);

  if (*head == NULL)
  {
    new_node->next = *head;
    *head = *tail = new_node;
    return;
  }

  new_node->next = *head;
  *head = new_node;
  (*tail)->next = *head;
}

node *ouroboros_head_delete(node *head, node *tail)
{
  node *temp;

  if (head == NULL)
    return NULL;

  temp = head->next;
  free(head);
  tail->next = temp;
  return temp;

}

void ouroboros_head_delete_fancy(node **head, node **tail)
{
  node *temp;

  if (head == NULL)
    return;

  temp = (*head)->next;
  free(*head);
  (*tail)->next = temp;
  *head = temp;
}

node *ouroboros_tail_insert(node *head, node *tail, int data)
{
  node *new_node = create_node(data);

  if (head == NULL)
  {
    new_node->next = head;
    return new_node;
  }

  tail->next = new_node;
  tail = tail->next;
  tail->next = head;
  return tail;
}

void *ouroboros_tail_insert_fancy(node **head, node **tail, int data)
{
  node *new_node = create_node(data);

  if (*head == NULL)
  {
    new_node->next = *head;
    *head = *tail = new_node;
  }

  (*tail)->next = new_node;
  *tail = (*tail)->next;
  (*tail)->next = *head;
}

node *ouroboros_tail_delete(node *head, node *tail)
{
  node *current;

  if (head == NULL || tail == NULL)
    return NULL;

  current = head;
  while (current->next != tail)
    current = current->next;

  free(current->next);
  tail = current;
  current->next = head;
  return head;
}

void *ouroboros_tail_delete_fancy(node **head, node **tail)
{
  node *current;

  if (*head == NULL || *tail == NULL)
    return NULL;

  current = *head;
  while (current->next != *tail)
    current = current->next;

  free(current->next);
  *tail = current;
  current->next = *head;
}

void print_circular_list(node *head)
{
  node *temp;

  if (head == NULL)
    return;

  printf("%d%c", head->data, (head->next == head) ? '\n' : ' ');

  for (temp = head->next; temp != head; temp = temp->next)
    printf("%d%c", temp->data, (temp->next == head) ? '\n' : ' ');
}

void do_print_circular_list(node *head)
{
  node *temp;

  if (head == NULL)
    return;

  temp = head;
  do
  {
    printf("%d%c", temp->data, (temp->next == head) ? '\n' : ' ');
    temp = temp->next;
  } while (temp != head);

}

void clever_print_circular_list(node *head)
{
  if (head == NULL)
    return;

  node *temp = head;

  while (temp != NULL)
  {
    printf("%d%c", temp->data, (temp->next == head) ? '\n' : ' ');
    temp = temp->next;

    if (temp == head)
      temp = NULL;
  }

}

void clever_print_circular_list_alternate(node *head)
{
  node *temp;

  temp = head;
  while (1)
  {
    printf("%d%c", temp->data, (temp->next == head) ? '\n' : ' ');
    temp = temp->next;

    if (temp == head)
      break;
  }
}

node *free_circular_list(node *head)
{
  node *current, *temp;

  if (head == NULL)
    return NULL;

  current = head;
  do
  {
    temp = current->next;
    free(current);
    current = temp;
  } while (current != head);

  return NULL;
}

int main(void)
{
  int array[] = {15, 24, 7, 1, 32}, n = 5, i;
	node *head = NULL, *tail = NULL;

	for (i = 0; i < n; i++)
	{
		ouroboros_head_insert_fancy(&head, &tail, array[i]);
	}

	print_circular_list(head);
	do_print_circular_list(head);
	clever_print_circular_list(head);
	clever_print_circular_list_alternate(head);
  head = ouroboros_head_delete(head, tail);
  tail = ouroboros_tail_insert(head, tail, 7);
  ouroboros_tail_insert_fancy(&head, &tail, 77);
  ouroboros_head_delete_fancy(&head, &tail);
  print_circular_list(head);
  // head = ouroboros_tail_delete(head, tail);
  ouroboros_tail_delete_fancy(&head, &tail);
  print_circular_list(head);

	// The following code is a relic from simpler days, when our
	// ouroboros_head_insert() function wasn't very fancy.

	// /*
	// for (i = 0; i < n; i++)
	// {
	// 	head = ouroboros_head_insert(head, tail, array[i]);
	// 	if (tail == NULL) tail = head;
	// }
	// */


	head = free_circular_list(head);

	return 0;
}
