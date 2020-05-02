#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define OH_NOOOO 1
#define HOORAY 0

typedef struct node
{
  struct node *left, *right;
  int data;
} node;

node *create_node(int data)
{
  node *new_node = calloc(1, sizeof(node));
  new_node->data = data;
  return new_node;
}

int regular_binary_tree_search(node *root, int key)
{
  if (root == NULL)
    return 0;

  else if (root->data == key)
    return 1;

  return (regular_binary_tree_search(root->left, key) || regular_binary_tree_search(root->right, key));
}

node *BST_insert(node *root, int data)
{
  if (root == NULL)
    return create_node(data);

  else if (data < root->data)
    root->left = BST_insert(root->left, data);
  else if (data > root->data)
    root->right = BST_insert(root->right, data);
  else
    ;

  return root;
}

int find_max_recursive(node *root)
{
  if (root == NULL)
    return INT_MIN;

  else if (root->right == NULL)
    return root->data;
  else
    return find_max_recursive(root->right);
}

int find_max_iterative(node *root)
{
  if (root == NULL)
    return INT_MIN;

  while (root->right != NULL)
    root = root->right;

  return root->data;
}

node *BST_delete(node *root, int data)
{
  node *temp;

  if (root == NULL)
    return NULL;
  else if (data < root->data)
    root->left = BST_delete(root->left, data);
  else if (data > root->data)
    root->right = BST_delete(root->right, data);
  else
  {
    if (root->right == NULL && root->left == NULL)
    {
      free(root);
      root = NULL;
    }

    else if (root->right == NULL)
    {
      temp = root->left;
      free(root);
      root = temp;
    }

    else if (root->left == NULL)
    {
      temp = root->right;
      free(root);
      root = temp;
    }

    else
    {
      root->data = find_max_recursive(root->left);
      root->left = BST_delete(root->left, root->data);
    }
  }

  return root;
}

void inorder_traversal(node *root)
{
  if (root == NULL)
    return;

  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);

}

void preorder_traversal(node *root)
{
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preorder_traversal(root->left);
  preorder_traversal(root->right);

}

void postorder_traversal(node *root)
{
  if (root == NULL)
    return;

  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->data);

}

void inorder_helper(node *root)
{
  if (root == NULL)
  {
    printf("Empty tree\n");
    return;
  }

  inorder_traversal(root);
  printf("\n");
}

void preoder_helper(node *root)
{
  if (root == NULL)
  {
    printf("Empty tree\n");
    return;
  }

  preorder_traversal(root);
  printf("\n");
}

void postorder_helper(node *root)
{
  if (root == NULL)
  {
    printf("Empty tree\n");
    return;
  }

  postorder_traversal(root);
  printf("\n");
}

node *forest_fire(node *root)
{
  if (root == NULL)
    return NULL;

  forest_fire(root->left);
  forest_fire(root->right);
  free(root);

}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int count_nodes(node *root)
{
  if (root == NULL)
    return 0;

  return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_nodes_condensed(node *root)
{
  return (root == NULL) ? 0 :  1 + count_nodes_condensed(root->left) + count_nodes_condensed(root->right);
}

int count_even_nodes(node *root)
{
  if (root == NULL)
    return 0;

  return (root->data % 2 == 0) + count_even_nodes(root->left) + count_even_nodes(root->right);
}

int height(node *root)
{
  if (root == NULL)
    return -1;

  return 1 + max(height(root->left), height(root->right));
}

int height_excessively_fancy(node *root)
{
  return (root == NULL) ? -1 : 1 + max(height_excessively_fancy(root->left), height_excessively_fancy(root->right));
}
int find_max(node *root)
{
  int m;

  if (root == NULL)
    return INT_MIN;

  m = max(find_max(root->left), find_max(root->right));

  return max(root->data, m);

}

int find_max_alternative(node *root)
{
  if (root == NULL)
    return INT_MIN;

  return max(root->data, max((find_max_alternative(root->left)),
                              find_max_alternative(root->right)));
}

node *bst_find_max_iterative(node *root)
{
  node *temp;

  if (root == NULL)
    return NULL;

  for (temp = root; temp->right != NULL; temp = temp->right)
    ;

  return root->right;
}

int bst_find_max(node *root)
{
  if (root == NULL)
    return INT_MIN;

  else if (root->right == NULL)
    return root->data;

  else
    return bst_find_max(root->right);
}

int BST_search(node *root, int data)
{
  if (root == NULL)
    return 0;

  else if (data < root->data)
    return BST_search(root->left, data);
  else if (data > root->data)
    return BST_search(root->right, data);
  else
    return 1;
}

int BST_search_iterative(node *root, int data)
{
  if (root == NULL)
    return 0;

  while (root != NULL)
  {
    if (data < root->data)
      root = root->left;
    else if (data > root->data)
      root = root->right;
    else
      return 1;
  }

  return 0;
}

int key_count(node *root, int key)
{
  if (root == NULL)
    return 0;

  else if (key == root->data)
    return 1 + key_count(root->left, key) + key_count(root->right, key);

  else
    return key_count(root->left, key) + key_count(root->right, key);
}

int key_count_fancy(node *root, int key)
{
  if (root == NULL)
    return 0;

  return (key == root->data) + key_count(root->left, key) + key_count(root->right, key);
}

int count_one_child_nodes(node *root)
{
  if (root == NULL)
    return 0;

  else if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL))
    return 1 + count_one_child_nodes(root->left) + count_one_child_nodes(root->right);
  else
    return count_one_child_nodes(root->left) + count_one_child_nodes(root->right);

}

int count_one_child_nodes_alt(node *root)
{
  int val = 0;

  if (root == NULL)
    return 0;
  else if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL))
    val = 1;
  else
    return val + count_one_child_nodes_alt(root->left) + count_one_child_nodes_alt(root->right);


}

int count_one_child_nodes_fancy(node *root)
{
  if (root == NULL)
    return 0;

  else if (root->left != NULL && root->right == NULL)
    return 1 + count_one_child_nodes_fancy(root->left);
  else if (root->right != NULL && root->left == NULL)
    return 1 + count_one_child_nodes_fancy(root->right);
  else
    return count_one_child_nodes_fancy(root->left) + count_one_child_nodes_fancy(root->right);

}

int has_some_negativity_in_its_life(node *root)
{
  if (root == NULL)
    return 0;

  if (root->data < 0)
    return OH_NOOOO;

  return has_some_negativity_in_its_life(root->left);
}

int has_some_negativity_in_its_life_iterative(node *root)
{
  if (root == NULL)
    return 0;

  while (root != NULL)
  {
    if (root->data < 0)
      return OH_NOOOO;

    root = root->left;
  }

  return HOORAY;
}

int count_leaf_nodes(node *root)
{
  if (root == NULL)
    return 0;

  else if (root->left == NULL && root->right == NULL)
    return 1;

  else
    return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);

}

int count_one_child_fancy(node *root)
{
  if (root == NULL)
    return 0;

  else if (root->right == NULL && root->left == NULL)
    return 0;

  else if (root->right == NULL || root->left == NULL)
    return 1 + count_one_child_fancy(root->left) + count_one_child_fancy(root->right);

  else
    return count_one_child_fancy(root->left) + count_one_child_fancy(root->right);

}

int count_one_child_FANCY(node *root)
{
  if (root == NULL)
    return 0;

  else if (root->left == NULL && root->right == NULL)
    return 0;

  else
    return (root->left == NULL || root->right == NULL) +
            count_one_child_FANCY(root->left) + count_one_child_FANCY(root->right);
}

int BST_count_greater(node *root, int key)
{
  if (root == NULL)
    return 0;

  else if (root->data > key)
    return 1 + BST_count_greater(root->left, key) + BST_count_greater(root->right, key);

  else
    return BST_count_greater(root->right, key);
}

int tree_diff(node *a, node *b)
{
  if (a == NULL && b == NULL)
    return 0;
  else if (a == NULL || b == NULL)
    return 1;
  else if (a->data == b->data)
    return 0;
  else if (a->data != b->data)
    return 1;
  else
    return (tree_diff(a->left, b->left) || tree_diff(a->right, b->right));
}










int main(void)
{
  return 0;
}
