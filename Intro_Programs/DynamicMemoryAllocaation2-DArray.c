#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int i, num_students, num_grades;

  // We saw that a dynamically allocated 1D integer array requires an int
	// pointer (i.e., int *array). With a 2D integer array, we need a double
	// integer pointer (i.e., int **array).

  // In this example, I'll use this array to hold all the numeric grades for
	// all the students in a class. I'll need a 2D array for that. The first
	// dimension will be the number of students in the class, and the second
	// dimension will be the number of grades I have for each student (exam
	// grades, assignment grades, etc.).

  int **array;

  printf("How many students are in the class");
  scanf("%d", &num_students);

  array = malloc(sizeof(int*) * num_students);
  // Now I have an array of addresses that I want to use to points to a bunch
	// of different arrays -- one for each student in the class. Assuming there
	// are just 5 students in my class, this is what memory looks like so far:
	//
	// array        0x1ef
	// +-------+    +-------+
	// | 0x1ef |    |       |
	// +-------+    +-------+
	//              |       |
	//              +-------+
	//              |       |
	//              +-------+
	//              |       |
	//              +-------+
	//              |       |
	//              +-------+

  printf("How many grades does each student have? ");
  scanf("%d", &num_grades);

  for (i = 0; i < num_students; i++)
    array[i] = malloc(sizeof(int) * num_grades);

    // At this point, I have five arrays of length 'num_grades' in memory. Assuming
  	// each students has, say, 8 grades this semester, memory now looks like this:
  	//
  	// array        0x1ef
  	// +-------+    +-------+
  	// | 0x1ef |    | 0x144 |  <-- this array (this first dimension of array) contains
  	// +-------+    +-------+      pointers to integer arrays (i.e., each cell is of
  	//              | 0x198 |      type (int *)). This, 'array' itself holds a pointer
  	//              +-------+      to that first (int *), and so 'array' must hold an
  	//              | 0x278 |      (int **) -- a pointer to an integer pointer.
  	//              +-------+
  	//              | 0x092 |
  	//              +-------+
  	//              | 0x554 |
  	//              +-------+
  	//
  	// 0x144
  	// +----+----+----+----+----+----+----+----+
  	// |    |    |    |    |    |    |    |    |
  	// +----+----+----+----+----+----+----+----+
  	// 0x198
  	// +----+----+----+----+----+----+----+----+
  	// |    |    |    |    |    |    |    |    |
  	// +----+----+----+----+----+----+----+----+
  	// 0x278
  	// +----+----+----+----+----+----+----+----+
  	// |    |    |    |    |    |    |    |    |
  	// +----+----+----+----+----+----+----+----+
  	// 0x092
  	// +----+----+----+----+----+----+----+----+
  	// |    |    |    |    |    |    |    |    |
  	// +----+----+----+----+----+----+----+----+
  	// 0x554
  	// +----+----+----+----+----+----+----+----+
  	// |    |    |    |    |    |    |    |    |
  	// +----+----+----+----+----+----+----+----+
  	//
  	//  ^ Individual grade arrays, one per student.


  	// Now, of course, we'd fill up the arrays with grades and do some processing.
  	// ...

  	// Before we can free 'array', we have to free the individual arrays it's
  	// pointing to. (Otherwise, we'll lose those memory addresses!) Two good
  	// rules of thumb for avoiding memory leaks are:
  	//
  	//    1. Generally, free nested dynamically allocated memory in the opposite
  	//       order from which it was allocated. (See below.)
  	//
  	//    2. For every call to malloc(), you (usually) want a corresponding call
  	//       to free() somewhere in your program.

  	// Free the individual arrays that hold student grades.

    for (i = 0; i < num_students; i++)
      free(array[i]);

    // Free the array that held the pointers to all those other arrays.
    free(array);

    return 0;

}
