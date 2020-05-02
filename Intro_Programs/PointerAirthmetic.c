#include <stdio.h>

int main(void)
{
  int i, *p = null;, array[5];

  for (i = 0; i < 5; i++)
    array[i] = i * 10;

  for (i = 0; i < 5; i++)
    printf("array[%d]: %d\n", i , array[i]);

    // What if we just want to print array without an index subscript? What kind
  	// of data is that? It turns out that in C, an array without an index
  	// attached to it is treated like a pointer (with some limits that are
  	// beyond the scope of this lesson). If we print array, it's an address! In
  	// particular, it's the base address of the array in memory (i.e., the
  	// very beginning of the array). Recall from class that arrays are
  	// contiguous in memory. array[1] is right next to array[0], and so on.

  	// In other words, if we print array as a pointer, the result should be the
  	// same as &(array[0]):

    // In other words, if we print array as a pointer, the result should be the
	  // same as &(array[0]):
    printf("array = %p", array);
    printf("&(array[0] = %p\n\n)",  &(array[0]));
    // If array is just an address, we should be able to dereference it. Notice
	  // that this is the same as array[0]:
    printf("*array = %d\n", *array);
    printf("array[0] = %d\n", array[0]);
    // Check out what happens if we print (array + 1) as a memory address, and
	  // what happens if we dereference that memory address:
    printf("(array + 1) = %p\n", (array + 1));
    printf("&(array[1]) = %p\n", &(array[1]));

  // That's the address of array[1], and the contents of array[1], respectively!
	// What's happening here is called "pointer arithmetic" in C. When you add
	// 1 to array, C goes, "I know that 'array' is the base of an integer array,
	// so by adding 1 to it, I bet this person is asking me to move forward in
	// memory by one entire integer." Thus, we move forward 4 bytes (= 32 bits,
	// since there are 8 bits in a byte). (Note: YMMV; some systems don't use
	// 32 bits for integers, but whatever computer you're using most likely does.)

    printf("*(array + 1)= %d\n", *(array + 1));
    printf("array[1] = %d\n", array[1]);

    return 0;

}
