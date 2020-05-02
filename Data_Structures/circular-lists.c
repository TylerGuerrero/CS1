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
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

node *ouroboros_head_insert(node *head, node *tail, int data)
{
  node *new_node = create_node(data);

  if (head == NULL)
  {
    new_node->next = head;
    return new_node;
  }

  new_node->next = head;
  tail->next = new_node;
  return new_node;
}

void ouroboros_head_insert_fancy(node **head, node **tail, int data)
{
	node *new_node = create_node(data);

	if (*head == NULL)
	{
		new_node->next = new_node;
		*head = *tail = new_node;
		return;
	}

	new_node->next = *head;
	*head = new_node;
	(*tail)->next = *head;
}

void print_circular_list(node *head)
{
  node *temp;

  if (head == NULL)
    return;

  printf("%d%c", head->data, (head->next == head) ? '\n' :  ' ');

  for (temp = head->next; temp != head; temp = temp->next)
    printf("%d%c", temp->data, (temp->next == head) ? '\n' : ' ');

}

void do_print_circular_list(node *head)
{
  node *temp = head;

  if (head == NULL)
    return;

  do
  {
    printf("%d%c", temp->data, (temp->next == head) ? '\n' : ' ');
    temp = temp->next;
  } while (temp != head);

}

void clever_print_circular_list(node *head)
{
  node *temp = head;

  if (head == NULL)
    return;

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
  node *temp = head;

  if (head == NULL)
    return;

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
