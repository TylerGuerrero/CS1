#include <stdio.h>
#include <stdlib.h>

int* create_array(int n)
{
  return malloc(sizeof(int) * n);
}

int main(void)
{
  int i, array* = NULL;


  printf("How many indicies do you want your array to have?\n");
  scanf("%d", &i);

  array = create_array(i);

  if (array == NULL)
  {
    printf("OH CRAP! That didn't work out!\n");

      // Notice that we can just return 1 (instead of calling exit(1))
      // since we are in main(). (To terminate execution from
      // another function, we would probably want to call exit().)
      return 1;
  }

  // ... use the array ...

   // Strictly speaking, this isn't necessary, since the program is
   // about to terminate. All dynamically allocated memory will
   // be released upon program termination. However, it's good
   // practice to get into the habit of cleaning up after yourself.

  free(array);


  return 0;
}
