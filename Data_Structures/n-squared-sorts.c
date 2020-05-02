#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *array, int i, int j)
{
  int temp;

  if (array == NULL)
    return;

  temp = array[i];
  array[i] = array[j];
  array[j] = temp;

}

// BUBBLE-SORT STEPS
// 1) i = 0
// 2) loop through the array n - 1 times
// 3) if array[i] > array[i + 1] then swap i , i + 1
// 4) i++

// Big-O Worst-Case: O(n^2), Best-Case: O(n)
// n being the number of elements in the array
void bubble_sort(int *array, int n)
{
  int i, swapped;

  if (array == NULL)
    return;

  swapped = 1;
  while (swapped)
  {
    swapped = 0;
    for (i = 0; i < n - 1; i++)
    {
      if (array[i] > array[i + 1])
      {
        swap(array, i, i + 1);
        swapped = 1;
      }
    }
  }

}

// BUBBLE-SORT ENHANCED STEPS
// 1) i = 0 , j = 0
// 2) loop through the array n - 1 - j times
// 3) if array[i] > array[i + 1] then swap i, i + 1
// 4) i++
// 5) j++

// Big-O Worst-Case: O(n^2), Best-Case: O(n)
// n being the number of elements in the array
void bubble_sort_enhanced(int *array, int n)
{
  int i, j, swapped;

  if (array == NULL)
    return;

  swapped = 1;
  j = 0;
  while (swapped)
  {
    swapped = 0;
    for (i = 0; i < n - 1 - j; i++)
    {
      if (array[i] > array[i + 1])
      {
        swap(array, i, i + 1);
        swapped = 1;
      }
    }
    j++;
  }

}

// SELECTION-SORT STEPS
// 1) i = 0
// 2) loop through the array n - 1 times and find the min between minIndex and i
// 3) swap i with minIndex
// 4) i++

// Big-O Worst-Case: O(n^2), Best-Case: O(n^2)
// n being the number of elements in the array
void selection_sort(int *array, int n)
{
  int i, j, minIndex;

  if (array == NULL)
    return;

  for (i = 0; i < n - 1; i++)
  {
    minIndex = i;
    for (j = i + 1; j < n; j++)
    {
      if (array[j] < array[minIndex])
        minIndex = j;
    }
    swap(array, minIndex, i);
  }

}

// INSERTION-SORT STEPS
// 1) i = 1
// 2) take it out
// 3) if gaps > i start the scooching proccess
// 4) i++

// Big-O Worst-Case: O(n^2), Best-Case: O(n)
// n being the number of elements in the array
void insertion_sort(int *array, int n)
{
  int i, j, gap, val;

  if (array == NULL)
    return;

  for (i = 1; i < n; i++)
  {
    val = array[i];
    gap = i;

    for (j = gap - 1; j >= 0 && array[j] > val; j--)
    {
      array[j + 1] = array[j];
      gap--;
    }
    array[gap] = val;
  }

}

// BUCKET-SORTS STEPS
// 1) find the max of the array
// 2) create buckets of max + 1 length and initialize elements to 0
// 3) map array values to bucket index and increment them.
// 4) loop through the buckets array and put the buckets index value
// in sorted order in the array while decrementing

// Big-O: O(n + m)
// n being the number of elements in the array
// m being the number of elements in the buckets Array
void bucket_sort(int *array, int n)
{
  int i, j, max, *buckets;

  if (array == NULL)
    return;

  max = array[0];
  for (i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];

  buckets = calloc(max + 1, sizeof(int));

  for (i = 0; i < n; i++)
    buckets[array[i]]++;

  for (i = j = 0; i <= max; i++)
  {
    while (buckets[i] > 0)
    {
      array[j++] = i;
      --buckets[i];
    }
  }

  free(buckets);

}

int main(void)
{
  return 0;
}
