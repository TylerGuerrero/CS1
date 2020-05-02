#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 57, *p;

  // This is what memory might look like right now. Notice that i and p are
	// boxes in memory, designed to hold data, each with a unique memory address:
	//
	// i  0x181  p       0x173
	// +------+  +-----------+
	// |  57  |  | (garbage) |
	// +------+  +-----------+
	//
	// (I made those memory addresses up.)

	// At this point, dereferencing p *might* cause a segfault. The dereference
	// operator says, "p holds an address. GO to that address (and mess with the
	// data that's stored there)!" This is a bad idea if the address stored in p
	// is gobbledygook. Who knows where we might end up?!
	// *p = 42;

	// This makes more sense: First, put the address of i in p:
  p = &i;
  // Now, memory looks like this:
	//
	// i  0x181  p       0x173
	// +------+  +-----------+
	// |  57  |  |   0x181   |
	// +------+  +-----------+

  *p = 42;
  // Notice that when we print &i and p, those are the same! Notice also that
	// &i and &p are different, and that i now has the value 42.
  printf("&i: %p\n", &i);
  printf("&p: %p\n" &p);
  printf("p: %p\n", p);
  printf("i: %d\n", i);
  printf("*p : %d\n", *p);
  // Now, what if we want to leave i be and create space to hold a new integer,
	// like this:

	// i  0x181  p       0x173     0x165
	// +------+  +-----------+  +------+
	// |  57  |  |   0x165   |  |      |
	// +------+  +-----------+  +------+
	//  (int)     (int *)        (int)

	// This requires DYNAMIC MEMORY ALLOCATION. We can do it with a function
	// called malloc().

	// When we call malloc(), we need to know two things:
	// a) how big is the box we want to create (for a given data type)?
	// b) how many such boxes should malloc() create?
	// ^ multiply these two to get the overall amount of memory to set aside

	// malloc() returns the address of the newly allocated space. Notice that
	// the new box in memory doesn't have a variable name. So, how will we access
	// it? (Correct! We'll store the address in p!)

	// Check your understanding: Which of these is correct?
	// *p = malloc(sizeof(int));
	// &p = malloc(sizeof(int));
	// p = malloc(sizeof(int));

	// The answer is....
  p = malloc(sizeof(int));

  //        ^ sizeof() takes a DATA TYPE as its argument and tells us how much
	//          space that data type takes up in memory! (This is essentially
	//          multiplied by 1 in this example, because we only want one integer
	//          box.)

  // Memory now looks like this (approximately):
	//
	// i  0x181  p       0x173     0x165
	// +------+  +-----------+  +------+
	// |  57  |  |   0x165   |  |      |
	// +------+  +-----------+  +------+

  *p = 53;
  // ... and now we have:
	//
	// i  0x181  p       0x173     0x165
	// +------+  +-----------+  +------+
	// |  57  |  |   0x165   |  |  53  |
	// +------+  +-----------+  +------+

	// This should print 53.
  printf("\n*p: %d\n", *p);

  free(p);

  // Notice what happens in memory if we call malloc() again:
  p = malloc(sizeof(int));

  // i  0x181  p       0x173     0x165     0x157
	// +------+  +-----------+  +------+  +------+
	// |  57  |  |   0x157   |  |  53  |  |      |
	// +------+  +-----------+  +------+  +------+

	// THIS IS AN EMERGENCY! We lost our reference to 0x165, and it's still
	// free-floating in memory! This is called a MEMORY LEAK and is a BIG DEAL
	// (especially when dealing with LOTS of dynamically allocated memory). If
	// we have huge memory leaks, memory can fill up quickly and slow down our
	// programs!

	// To avoid memory leaks, we first free the memory we will no longer be
	// using:
  free(p);
  // After freeing a piece of memory, it is also good practice to get rid of
	// all references to that address. Since it has been freed, we have no
	// business messing with it anymore.
  p = NULL;

  return 0;



}
