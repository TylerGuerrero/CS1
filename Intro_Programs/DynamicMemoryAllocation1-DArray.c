#include <stdio.h>
#include <stdlib.h>

void panic(char *arr_msg)
{
  fprintf(stderr,"%s",err_msg);
  exit(1);
}
int main(void)
{
  int i, n, *a = NULL;

  printf("How many integers do you want int he array");
  scanf("%d", &n);

  // We saw that malloc() wants to know how big of a block to find in memory.
	// For arrays, which are contiguous in memory, we can tell malloc() how big
	// the block needs to be by supplying two pieces of information:
	//
	// a) the size of the data type we're storing in the array.
	// b) the number of elements we'll be storing in the array.
	// ^ multiply these two to get the overall amount of memory to set aside

	// So, to allocate an array that can hold n integers, we use:

  a = malloc(sizeof(int) * n);

  // Check whether malloc() was successful.
  if (a == NULL)
    printf("ERROR! Could not allocate enough memory in main()!\n");
  // Now you can access the individual elements in 'a' as if it were any
  	// other array you've ever messed around with. Here, I'm just storing
  	// multiples of 10:
  for (i = 0; i < n; i++)
  {
    a[i] = i * 10;
  }
  // Let's print those out for posterity:
  for (i = 0; i < n; i++)
  {
    printf("a[%d] = %d\n", i, a[i]);
  }
  printf("\n");



  // NOTE: When you call free() on a dynamically allocated array, the ENTIRE
	// block of memory associated with that array is wiped out. You do NOT have
	// to free each element individually.
  free(a);
  // NOTE: One interesting thing is, if we had just allocated space for a
	// single integer, this would still work! Check it out:
  a = malloc(sizeof(int));

  // Now, we can just dereference 'a' like we dereferenced 'p' in the previous
	// file (dma_part1.c), --or-- we can use our array notation. These two lines
	// are equivalent:
  *a = 52;
  a[0] = 52;

  // Similarly, we can print the value in that single integer cell using
	// either notation:
	printf("*a: %d\n", *a);
	printf("a[0]: %d\n\n", a[0]);


  	// So, what we start to see is that there's a strong relationship between
  	// pointers and arrays. In particular, what a[i] means in C is: 'a' is the
  	// base of an array (whose type is declared and known), so GO to the base
  	// of that array, then skip forward 'i' spaces. (If we're dealing with
  	// integers, skipping forward a single space means skipping forward to the
  	// next integer -- 4 bytes (or 32 bits) on most systems, although YMMV.)

  	// For more on this, see dma_part3.c, where I talk about pointer arithmetic.

  	return 0;
  









}
