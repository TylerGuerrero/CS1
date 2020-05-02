// Sean Szumlanski
// COP 3502, Summer 2018

// MergeSort-abbreviated.c
// =======================
// A slightly abbreviated version of the MergeSort function.

#include <stdio.h>
#include <stdlib.h>

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
	MergeSort(array, mid+1, hi);

	// Mergey merge.
	aux = malloc(sizeof(int) * (hi - lo + 1));

	while (i <= mid || j <= hi)
	{
		// This is the part we abbreviated.
		if (i > mid || (j <= hi && array[j] < array[i]))
			aux[k++] = array[j++];
		else
			aux[k++] = array[i++];
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
	MergeSort(array, 0, n - 1);

	// Print the sorted array.
	printf("\nSorted array:\n");
	printArray(array, n);

	printf("\n%s\n", isSorted(array, n) ? "HOORAY!" : "fail whale :(");

	// Clean up after yourself.
	free(array);

	return 0;
}
