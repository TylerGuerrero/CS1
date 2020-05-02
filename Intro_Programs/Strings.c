// Strings in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A case insensative string compare.
int strcmp_i(const char *str1, const char *str2)
{
  int len1, len2, i;

  if (str1 == NULL || str2 == NULL)
    return 0;

  len1 = strlen(str1);
  len2 = strlen(str2);

  if (len1 != len2)
    return 0;

  for (i = 0; str1[i] != '\0'; i++)
  {
    if (toupper(str1[i]) != toupper(str2[i]))
      return 0;
  }

  return 1;

}

// dma_strings.c
// =============
// This file revisits dynamic allocation of strings. It then touches on some
// problems with assigning string literals (i.e, str = "word"), how to
// properly copy strings with the strcpy() function, and how to properly compare
// two strings for equality with strcmp().

int main(void)
{
	char *str1 = NULL, *str2 = NULL, *str3 = NULL, *str4 = NULL;
	int slen1 = 4, slen2 = 4, slen3 = 4, slen4 = 4;

	str1 = malloc(sizeof(char) * (slen1 + 1));
	str2 = malloc(sizeof(char) * (slen2 + 1));
  str3 = malloc(sizeof(char) * (slen3 + 1));
  str4 = malloc(sizeof(char) * (slen4 + 1));

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
	strcpy(str2, "Sean");

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

  strcpy(str3, "sean");
  strcpy(str4, "SeAn");

	// Notice that if we want to check for string equality, the == operator is
	// not a good idea! Why not?

	if (str1 == str2)
		printf("(b) The strings are equal!\n");

  // Case insensative string compare.
  if (strcmp_i(str1,str2))
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
		printf("(b) The strings are equal!\n");

	// We could also do this, since the ! operator changes 0 to 1 (false to true)
	// and any non-zero value to 0 (true to false):

	if (!strcmp(str1, str2))
		printf("(c) The strings are equal!\n");

  free(str1);
  free(str2);
  free(str3);
  free(str4);

	return 0;
}
