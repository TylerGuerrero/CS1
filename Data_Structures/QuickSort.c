#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *array, int i, int j)
{
  if (array == NULL)
    return;

  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int partition(int *array, int lo, int hi, int pivot)
{

  if (array == NULL)
    return 0;

  while (lo <= hi)
  {
    while (array[lo] < pivot)
      lo++;

    while (array[hi] > pivot)
      hi--;

    if (lo <= hi)
    {
      swap(array, lo, hi);
      lo++;
      hi--;
    }
  }

  return lo;
}

int partitionPractice(int *array, int lo, int hi, int pivot)
{
  if (array == NULL)
    return INT_MIN;

  while (lo <= hi)
  {
    while (array[lo] < pivot)
      lo++;

    while (array[hi] > pivot)
      hi--;

    if (lo <= hi)
    {
      swap(array, lo, hi);
      lo++;
      hi--;
    }
  }

  return lo;
}

void quicksortPractice(int *array, int lo, int hi)
{
  if (array == NULL)
    return;

  if (lo >= hi)
    return;

  int pivot = array[lo + (hi - lo) / 2];
  int index = partitionPractice(array, lo, hi, pivot);
  quicksortPractice(array, lo, index - 1);
  quicksortPractice(array, index, hi);

}

// call it like quicksort(array, 0, N - 1)
// Big-O Worst-Case: O(n^2), Best-Case: O(nlogn)
void quicksort(int *array, int lo, int hi)
{
  if (array == NULL)
    return;

  if (lo >= hi)
    return;

  int pivot = array[lo + (hi - lo) / 2];
  int index = partition(array, lo, hi, pivot);
  quicksort(array, lo, index - 1);
  quicksort(array, index, hi);

}



void printArray(int *array, int n)
{
  int i;

  if (array == NULL)
    return;

  for (i = 0; i < n; i++)
    	printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');
}

int main(void)
{
  int i, n;
  int *array;

  n = 12;
  array = malloc(sizeof(int) * n);

	// Populate our array with random numbers on the range [1, 1000].
	for (i = 0; i < n; i++)
		array[i] = rand() % 1000 + 1;

  // Print the unsorted array.
	printf("\nUnsorted array:\n");
	printArray(array, n);

	// Sort the array.
	quicksort(array, 0, n - 1);

	// Print the sorted array.
	printf("\nSorted array:\n");
	printArray(array, n);

  return 0;
}
