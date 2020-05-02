# include <stdio.h>
/*
This is supplementary information that I hope to touch on soon, but it's related to
how strcmp() compares strings that are spelled the same, but with different casing
(e.g., "perspicacity" vs. "Perspicacity"). In C, every character has an underlying
integer value. There is an international standard that governs these values, called ASCII
(Links to an external site.)Links to an external site.. In ASCII, sequential alphabetic
 letters have sequential values. So, for example, 'a' is 97, 'b' is 98, 'c' is 99, and so on.

Thus, if you want to convert the lowercase alphabetic letters 'a' through 'z' to
 integers 0 through 25, you can simply subtract 97 from them (or, to future-proof
  your code, you could subtract 'a', which currently is the same thing as 97). For example:


*/
int main(void)
{
  char letter;

  for (letter = 'a'; letter <= 'z'; letter++)
    printf("The ASCII value for %c is %d\n", letter, letter);

    printf("\n\n");

  // Convert letters 'a', 'b', and 'c' to 0, 1, and 2, respectively.
  for (letter = 'a'; letter <= 'z'; letter++)
    printf("%c -> %d\n", letter, letter - 'a');

  return 0;
}
