// Sean Szumlanski
// COP 3502, Summer 2018

// radix-sort.c
// ============
// Implementation of Radix Sort that uses queues for the 10 buckets. To compile
// at the command line:
//
//    gcc radix.c queue.c node.c

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define LENGTH 7

// RADIX-SORT STEPS
// 1) Create ten buckets of Queue's to represent base 10 digits 0 - 9
// 2) Find the max element in the array
// 3) make k passes through the buckets k being the number of digits in the max element
// 4) Enqueue array values into the buckets by mapping them to the buckets by pow
// 5) Dequeue the buckets

// Big-O Worst-Case O(nk)
// n = the number of elements in the array
// k being the number of digits in the max element
// or O(nlogm) if we call m our max element
void RadixSortPractice_1(int *array, int n)
{
	int i, j, max, pow;
	Queue **buckets;

	if (array == NULL)
		return;

	buckets = calloc(10, sizeof(Queue*));

	for (i = 0; i < 10; i++)
		buckets[i] = initQueue();

	max = array[0];
	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];

	for (pow = 1; max / pow > 0; pow *= 10)
	{
		for (i = 0; i < n; i++)
			enqueue(buckets[array[i] / pow % 10], array[i]);

		for (i = j = 0; i < 10; i++)
			while (!isEmpty(buckets[i]))
				array[j++] = dequeue(buckets[i]);
	}

	for (i = 0; i < 10; i++)
		free(buckets[i]);

	free(buckets);

}
void RadixSortPractice(int *array, int n)
{
	int i, j, max, pow;
	Queue **buckets;

	if (array == NULL)
		return;

	buckets = calloc(10 , sizeof(Queue*));

	for (i = 0; i < 10; i++)
		buckets[i] = initQueue();

	max = array[0];
	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];

	for (pow = 1; max / pow > 0; pow *= 10)
	{
		for (i = 0; i < n; i++)
			enqueue(buckets[array[i] / pow % 10], array[i]);

		for (i = j = 0; i < 10; i++)
			while (!isEmpty(buckets[i]))
				array[j++] = dequeue(buckets[i]);
	}

	for (i = 0; i < 10; i++)
		free(buckets[i]);

	free(buckets);
}

void RadixSort(int *array, int n)
{
	int i, j, pow, max = array[0];

	Queue *buckets[10];

	// create some buckets
	for (i = 0; i < 10; i++)
		buckets[i] = initQueue();

	// find the max element in the array
	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];

	// Recall that if we want to pull out the ones, tens, or hundreds digits of
	// some number, we can use:

	// 402 % 10 = 2         <- ones digit
	// 402 / 1 % 10 = 2     <- also for the ones digit
	// 402 / 10 % 10 = 0    <- tens digit
	// 402 / 100 % 10 = 4   <- hundreds digit

	// loop for each digit in the max integer
	for (pow = 1; max / pow > 0; pow *= 10)
	{
		// place into buckets
		for (i = 0; i < n; i++)
			enqueue(buckets[ array[i] / pow % 10 ], array[i]);

		// pull out of buckets and into the original array
		for (i = j = 0; i < 10; i++)
			while (!isEmpty(buckets[i]))
				array[j++] = dequeue(buckets[i]);
	}

	// clean up after yourself
	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

// Print an array of n integers, space-separated, followed by two newline chars.
void printArray(int *array, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');

	printf("\n");
}

int main(void)
{
	// Note: Since LENGTH is #defined, we don't need to do this dynamically...
	int i, *array = malloc(sizeof(int) * LENGTH);

	// Seed the random number generator.
	srand(time(NULL));

	// Populate our array with random numbers on the range [0, 99].
	for (i = 0; i < LENGTH; i++)
		array[i] = rand() % 100;

	// Print the unsorted array.
	printf("Unsorted array:\n");
	printArray(array, LENGTH);

	// Sort the array.
//	RadixSort(array, LENGTH);
	RadixSortPractice(array, LENGTH);

	// Print the sorted array.
	printf("Sorted array:\n");
	printArray(array, LENGTH);

	printf("You need to implement the functions queue.c before this will work.\n\n");

	return 0;
}
