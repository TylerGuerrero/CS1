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

  if (new_node == NULL)
  {
    printf("Could not allocate memory");
    return NULL;
  }

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

node *destroy_linked_list(node *head)
{
  node *current, *temp;

  if (head == NULL)
  {
    printf("Empty List\n");
    return NULL;
  }

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

  printf("Destroying the node with %d...\n", head->data);
  free(head);
}

void reverse_print_list_helper(node *head)
{
  if (head == NULL)
    return;

  reverse_print_list_helper(head->next);
  printf("%d ", head->data);
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
    printf("Empty list\n");
    return;
  }

  for (temp = head; temp != NULL; temp = temp->next)
    printf("%d%c", temp->data, ((temp->next == NULL) ? '\n' : ' '));

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

void print_list_recursive_helper(node *head)
{
  if (head == NULL)
    return;

  printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
  print_list_recursive_helper(head->next);

}

void print_list_recursive(node *head)
{
  if (head == NULL)
  {
    printf("Empty List\n");
    return;
  }

  print_list_recursive_helper(head);

}

node *deleteNth(node *head, int n)
{
  node *temp, *current;
  int i;

  if (head == NULL)
  {
    printf("Empty List\n");
    return NULL;
  }

  if (n == 0)
  {
    current = head->next;
    free(head);
    return current;
  }

  current = head;
  i = 0;

  while (current->next != NULL && i < n - 1)
  {
    current = current->next;
    i++;
  }

  if (current->next == NULL)
  {
    printf("You went to far in the list not enough nodes now returning a NULL pointer\n");
    return NULL;
  }

  temp = current->next->next;
  free(current->next);
  current->next = temp;

  return head;
}

node *deleteNthRecursive(node *head, int n)
{
  node *current;

  if (n < 0)
    return head;

  if (head == NULL)
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
  node *next, *current, *temp;

  if (head == NULL)
  {
    printf("Empty List\n");
    return NULL;
  }

  current = head;
  next = current->next;

  while (current != NULL && next != NULL)
  {
    current->next = next->next;
    free(next);
    current = current->next;

    // check for the end of the list.
    if (current != NULL)
      next = current->next;
  }

  return head;
}

node *deleteAltRecursive_1(node *head)
{
  node *next;

  if (head == NULL)
    return NULL;

  next = head->next;

  if (next == NULL)
    return NULL;

  head->next = next->next;
  free(next);

  deleteAltRecursive_1(head->next);

  return head;
}

// wrong. works sometimes.edges cases side by side even nodes.
// Last node. First node.
node *deleteEvenNodes(node *head)
{
  node *current, *temp;

  if (head == NULL)
    return NULL;

  current = head;

  while (current->next != NULL)
  {
    if ((current->next->data % 2) == 0)
    {
      temp = current->next->next;
      free(current->next);
      current->next = temp;
    }

    current = current->next;
  }

  return head;
}

void headInsert(node **head, int data)
{
  if (head == NULL)
    return;

  node *new_head = create_node(data);
  new_head->next = *head;
  *head = new_head;
}

node *insertSortedNode(node *head, int n)
{
  node *current, *temp;

  if (head == NULL || head->data >= n)
    return head_insert(head, n);

  current = head;

  while (current->next != NULL && current->next->data < n)
    current = current->next;

    temp = create_node(n);
    temp->next = current->next;
    current->next = temp;

    return head;
}


int main(void)
{
  node *head = NULL, *tail = NULL;
	int i, r, n = 5;

	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		printf("Inserting %d...\n", r = rand() % 100 + 1);
		tail = tail_insert(tail, r);

		// If the list was empty, we also need to update the head pointer. (The
		// single node in the linked list is both the head and the tail.)
		if (head == NULL)
			head = tail;
	}

	printf("\nprint_list(head):\n");
	print_list(head);

	printf("\nrecursive_print_list(head):\n");
	print_list_recursive(head);

	printf("\nreverse_print_list(head):\n");
	reverse_print_list(head);

  printf("\nprint_list(head):\n");
  head = deleteAltRecursive_1(head);
  print_list(head);

	// Clean up after yourself.
	head = alternative_recursive_destroy_linked_list(head);

	return 0;
}
