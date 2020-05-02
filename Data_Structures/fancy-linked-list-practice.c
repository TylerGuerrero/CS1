// LinkedList with a head and tail pointer.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct LinkedList
{
  node *head;
  node *tail;
} LinkedList;

LinkedList *create_list(void)
{
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

node *create_node(int data)
{
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

void print_list(node *head)
{
  if (head == NULL)
    return;

  printf("%d%c", head->data, (head->next == NULL) ? '\n' :' ');
  print_list(head->next);

}

node *destroy_list(node *head)
{
  if (head == NULL)
    return NULL;

  destroy_list(head->next);
  free(head);

  return NULL;

}

void print_linked_list(LinkedList *list)
{
  if (list == NULL)
  {
    printf("Empty List\n");
    return;
  }

  print_list(list->head);

}

LinkedList *destroy_linked_list(LinkedList *list)
{
  if (list == NULL)
  {
    printf("Empty List\n");
    return NULL;
  }

  destroy_list(list->head);
  free(list);

  return NULL;

}

void tail_insert(LinkedList *list, int data)
{
  if (list == NULL)
    return;

  else if (list->tail == NULL)
    list->head = list->tail = create_node(data);

  else
  {
    list->tail->next = create_node(data);
    list->tail = list->tail->next;
  }

}

void head_insert(LinkedList *list, int data)
{
  node *new_head;

  if (list == NULL)
    return;

  else if (list->head == NULL)
    list->head = list->tail = create_node(data);

  else
  {
    new_head = create_node(data);
    new_head->next = list->head;
    list->head = new_head;
  }
}

int main(int argc, char **argv)
{
	LinkedList *list = create_list();

	int i, r, n;

	if (argc < 2)
	{
		// Avoid fringe memory leak. This is pedantic.
		free(list);

		printf("The proper syntax for running this program is: %s <n>\n", argv[0]);
		return 1;
	}

	// Read command line argument.
	n = atoi(argv[1]);

	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		// Notice how much easier it is to call our insertion function now. We
		// don't need to worry about remembering to capture its return value!
		printf("Inserting %d...\n", r = rand() % 100 + 1);
		tail_insert(list, r);
	}

	print_linked_list(list);

	// Clean up after yourself.
	list = destroy_linked_list(list);

	return 0;
}
