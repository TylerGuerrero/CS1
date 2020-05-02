// Sean Szumlanski
// COP 3502, Summer 2018

// MergeSort.c
// ===========
// Implementation of merge sort from class.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// MERGE-SORT STEPS
// 1) check if lo >= hi BASE CASE (One single element)
// 2) Split the array by the left half then the right half recursively
// 3) Create a auxillary array and Sort the spilt array sections into it
// 4) Loop through the array with lo and hi and insert aux values into the array

// Big-O Worst-Case: O(nlogn), Best-Case: O(nlogn)
void MergeSortPractice(int *array, int lo, int hi)
{
	int mid, i, j, k;
	int *aux;

	if (array == NULL)
		return;

	if (lo >= hi)
		return;

	i = lo;
	mid = lo + (hi - lo) / 2;
	j = mid + 1;
	k = 0;


	MergeSortPractice(array, lo, mid);
	MergeSortPractice(array, mid + 1, hi);

	aux = malloc(sizeof(int) * (hi - lo + 1));

	while (i <= mid || j <= hi)
	{
		if (i > mid)
			aux[k++] = array[j++];
		else if (j > hi)
			aux[k++] = array[i++];
		else if (array[i] > array[j])
			aux[k++] = array[j++];
		else
			aux[k++] = array[i++];
	}

	for (i = lo; i <= hi; i++)
		array[i] = aux[i - lo];

	free(aux);

}

// For an array of N integers, call this using: MergeSort(array, 0, N-1);
void MergeSort(int *array, int lo, int hi)
{
	int mid = lo + (hi - lo) / 2, i = lo, j = mid + 1, k = 0;

	int *aux = NULL;

	// Base case: One (or fewer) elements in this portion of the array.
	if (lo >= hi)
		return;

	// Recursive calls.
	MergeSort(array, lo, mid);
	MergeSort(array, mid + 1, hi);

	// Mergey merge.
	aux = malloc(sizeof(int) * (hi - lo + 1));

	while (i <= mid || j <= hi)
	{
		// i is done iterating you just need the rest of your j values
		if (i > mid)
			aux[k++] = array[j++];
		// j is done iterating you just need the rest of your i values
		else if (j > hi)
			aux[k++] = array[i++];
		else if (array[i] < array[j])
			aux[k++] = array[i++];
		else
			aux[k++] = array[j++];
	}

	// Copy everything from the auxiliary array back into the original array.
	for (i = lo; i <= hi; i++)
		array[i] = aux[i - lo];

	// Clean up after yourself.
	free(aux);
}


void printArray(int *array, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');
}

// Returns 1 if the array is sorted, 0 otherwise.
int isSorted(int *array, int n)
{
	int i;

	for (i = 0; i < n - 1; i++)
		if (array[i] > array[i + 1])
			return 0;

	return 1;
}

int main(int argc, char **argv)
{
	int i, n, *array;
	srand(time(NULL));

	if (argc < 2)
	{
		fprintf(stderr, "Proper syntax: %s <n>\n", argv[0]);
		return 1;
	}

	// Array length is passed in as a command line argument.
	n = atoi(argv[1]);
	array = malloc(sizeof(int) * n);

	// Populate our array with random numbers on the range [1, 1000].
	for (i = 0; i < n; i++)
		array[i] = rand() % 1000 + 1;

	// Print the unsorted array.
	printf("\nUnsorted array:\n");
	printArray(array, n);

	// Sort the array.
	MergeSortPractice(array, 0, n - 1);

	// Print the sorted array.
	printf("\nSorted array:\n");
	printArray(array, n);

	printf("\n%s\n", isSorted(array, n) ? "HOORAY!" : "fail whale :(");

	// Clean up after yourself.
	free(array);

	return 0;
}
