#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  char *str1 = NULL, *str2 = NULL, name* = "Sean";
  int slen1 = 4, slen = 4;

  str1 = malloc(sizeof(char) * (slen1 + 1));
  str2 = malloc(sizeof(char) * (slen2 + 1));


  // str1
	// +-------+
	// | 0x1ef |
	// +-------+

	// str2
	// +-------+
	// | 0x262 |
	// +-------+

	//                 0x1ef
	// +---+---+---+---+---+
	// |   |   |   |   |   |  (str1)
	// +---+---+---+---+---+

	//                 0x262
	// +---+---+---+---+---+
	// |   |   |   |   |   |  (str2)
	// +---+---+---+---+---+

	// Now, suppose we do this to put "Sean" into str1:
	// str1 = "Sean";

	// This creates a MEMORY LEAK! We lose our reference to 0x1ef! Here's what
	// is *actually* happening in memory when we use str1 = "Sean":

	// str1
	// +-------+
	// | 0x118 |
	// +-------+
	//
	// str2
	// +-------+
	// | 0x262 |
	// +-------+
	//
	// 0x1ef
	// +---+---+---+---+---+
	// |   |   |   |   |   |  (str1)
	// +---+---+---+---+---+
	//
	// 0x262
	// +---+---+---+---+---+
	// |   |   |   |   |   |  (str2)
	// +---+---+---+---+---+
	//
	// 0x118
	// +---+---+---+---+---+
	// | S | e | a | n | \0|  ("Sean")  NOTE: This is read-only memory! If you
	// +---+---+---+---+---+            try writing to it, you'll crash!

	// Let's not do that! Instead, the proper approach is:

  strcpy(str1, "Sean");

  // Now (assuming we comment out the line that says str1 = "Sean") we have:
	//
	// str1
	// +-------+
	// | 0x1ef |
	// +-------+
	//
	// str2
	// +-------+
	// | 0x262 |
	// +-------+
	//
	// 0x1ef
	// +---+---+---+---+---+
	// | S | e | a | n | \0|  (str1)
	// +---+---+---+---+---+
	//
	// 0x262
	// +---+---+---+---+---+
	// |   |   |   |   |   |  (str2)
	// +---+---+---+---+---+

	// Now suppose we also copy "Sean" into str2:

  strcpy(str2, str1);

  // Memory now looks like this (again, assuming we never used str1 = "Sean"):

	// str1
	// +-------+
	// | 0x1ef |
	// +-------+
	//
	// str2
	// +-------+
	// | 0x262 |
	// +-------+
	//
	// 0x1ef
	// +---+---+---+---+---+
	// | S | e | a | n | \0|  (str1)
	// +---+---+---+---+---+
	//
	// 0x262
	// +---+---+---+---+---+
	// | S | e | a | n | \0|  (str2)
	// +---+---+---+---+---+

	// Notice that if we want to check for string equality, the == operator is
	// not a good idea! Why not?

  if (str1 == str2)
    printf("(a) The strings are equal!\n");

  // str1 and str2 are memory addresses! In the diagram above, str1 holds the
	// value 0x1ef, and str2 is 0x262! Clearly, 0x1ef is not equal to 0x262, so
	// the comparison there is false.

	// To compare strings, we need a function that goes character-by-character to
	// see whether we've got the same strings. That function is strcmp() (for
	// "string compare," and to use it, we #include <string.h>.

  // strcmp(str1, str2) returns:
	//
	//    a value < 0 if str1 comes before str2 in lexicographic order
	//                   (i.e., str1 is "less than" str2)
	//
	//    the value 0 if str1 and str2 are equivalent
	//                   (i.e., str1 is "equal to" str2)
	//
	//    a value > 0 if str1 comes after str2 in lexicographic order
	//                   (i.e., str1 is "greater than" str2)

	// So, here's the correct way to test for string equality in C:

  if (strcmp(str1, str2) == 0)
    printf("(b) The strings are equal !\n");

    // We could also do this, since the ! operator changes 0 to 1 (false to true)
  	// and any non-zero value to 0 (true to false):

  if (!(strcmp(str1, str2)))\
    printf("The strings are equal\n");
  // Will crash, read in memory only.
  name[0] = 's';
  // Will crash, read in memory only.
  printf("The name is %s\n", name);

  return 0;


}
