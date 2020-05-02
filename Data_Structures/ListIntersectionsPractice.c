#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAN_VAL 50

// Big-O Worst-Case: O(n), Best-Case: O(1).
int linear_search(int *array, int n, int key)
{
  int i;

  if (array == NULL || n == 0)
    return 0;

  for (i = 0; i < n; i++)
    if (key == array[i])
      return 1;

  return 0;

}

// Big-O Worst-Case: O(logn), Best-Case: O(1).
int binary_search(int *array, int n, int key)
{
  int lo, mid, hi;

  if (array == NULL || n == 0)
    return 0;

  lo = 0;
  hi = n - 1;

  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;

    if (key < array[mid])
      hi = mid - 1;
    else if (key > array[mid])
      lo = mid + 1;
    else
      return 1;
  }

  return 0;

}

int my_compare (const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}

// Big-O Worst-Case: O(n^2), Best-Case: O(nlogn)
int *create_sorted_array(int n)
{
  int i, *array;

  if (n == 0)
    return NULL;

  array = malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
    array[i] = rand() % MAX_RAN_VAL + 1;

  qsort(array, n, sizeof(int), my_compare);
  return array;

}

// Big-O Worst-Case: O(n), Best-Case: O(n).
void print_array(int *array, int n)
{
  int i;

  if (array == NULL || n == 0)
    return;

  for (i = 0; i < n; i++)
    printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');

  printf("\n");
}

// Worst-Case: O(n^2), Best-Case: O(n).
void print_list_intersection(int *array1, int len1 , int *array2, int len2)
{
  int i;

  if (array1 == NULL || len2 == 0 || array2 == NULL || len2 == 0)
    return;

  for (i = 0; i < len1; i++)
    if (linear_search(array2, len2, array1[i]));
      printf("Both arrays have  %d\n", array1[i]);

  printf("\n\n");
  return;

}

// Big-O Worst-Case: O(nlogn), Best-Case: O(n).
void print_list_intersection_fancy(int *array1, int len1, int *array2, int len2)
{
  int i;

  if (array1 == NULL || len1 == 0 || array2 == NULL || len2 == 0)
    return;

  for (i = 0; i < len1; i++)
    if (binary_search(array2, len2, array1[i]))
      printf("Both arrays have %d\n", array1[i]);

  printf("\n\n");
  return;

}

// Big-O Worst-Case: O(n), Best-Case: O(n)
void print_list_intersection_fanciest(int *array1, int len1, int *array2, int len2)
{
  int i, j;

  if (array1 == NULL || len1 == 0 || array2 == NULL || len2 == 0)
    return;

  i = 0;
  j = 0;

  while (i < len1 && j < len2)
  {
    if (array1[i] < array2[j])
      ++i;
    else if (array1[i] > array2[j])
      ++j;
    else
    {
      printf("Both arrays have %d\n", array1[i]);
      ++i;
      ++j;
    }
  }

  printf("\n\n");

}

// Big-O Worst-Case: O(n), Best-Case: O(n).
int *create_sorted_array_fancy(int n)
{
  int i, *array;

  if (n == 0)
    return NULL;

  array = malloc(sizeof(int) * n);

  array[0] = rand() % MAX_RAN_VAL + 1;
  for (i = 1; i < n; i++)
    array[i] = array[i - 1] + (rand() % MAX_RAN_VAL + 1);

  return array;

}

// Big-O Worst-Case: O(n^2), Best-Case: O(1).
int canMakeSum(int *array, int n, int key)
{
  int i;

  if (array == NULL || n == 0)
    return 0;

  for (i = 0; i < n; i++)
    if (linear_search(array, n, key - array[i]))
      return 1;

  return 0;
}

// Big-O Worst-Case: O(nlogn), Best-Case: O(1).
int canMakeSumFancy(int *array, int n, int key)
{
  int i;

  if (array == NULL || n == 0)
    return 0;

  for (i = 0; i < n; i++)
    if (binary_search(array, n, key - array[i]))
      return 1;

  return 0;

}

// Big-O Worst-Case: O(n), Best-Case: O(1)
int canMakeSumFanciest(int *array, int n, int key)
{
  int i, j, sum;

  if (array == NULL || n == 0)
    return 0;

  i = 0;
  j = n - 1;

  while (i < j)
  {
    sum = array[i] + array[j];

    if (sum < key)
      ++i;
    else if (sum > key)
      --j;
    return 1;
  }

  return 0;

}

// Big-O Worst-Case: O(n), Best-Case: O(n)
int keyCounter(int *array, int n, int key)
{
  int i, counter;

  if (array == NULL || n == 0)
    return 0;

  counter = 0;
  for (i = 0; i < n; i++)
    if (key == array[i])
      counter++;

  return counter;

}

// Big-O Worst-Case: O(logn + n), Best-Case: O(logn)
int keyCounterFancy(int *array, int n, int key)
{
  int lo, mid, hi, left, right, counter;

  if (array == NULL || n == 0)
    return 0;

  lo = 0;
  hi = n - 1;
  left = right = counter = 0;

  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;

    if (key > array[mid])
      lo = mid + 1;
    else if (key < array[mid])
      hi = mid - 1;
    else
    {
      left = mid - 1;
      while (left >= 0 && array[left] == key)
      {
        left--;
        counter++;
      }

      right = mid + 1;
      while (right < n && array[right] == key)
      {
        right++;
        counter++;
      }
    }
  }

  return counter;
}

// Big-O Worst-Case: O(logn), Best-Case: O(logn)
int keyCounterFanciest(int *array, int n, int key, int leftMost)
{
  int lo, mid, hi, idx;

  if (array == NULL || n == 0)
    return 0;

  lo = 0;
  hi = n - 1;

  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;

    if (key < array[mid])
      hi = mid - 1;
    else if (key > array[mid])
      lo = mid - 1;
    else
    {
      idx = mid;

      if (leftMost)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
  }

  return idx;
  
}

int main(void)
{
  return 0;
}
