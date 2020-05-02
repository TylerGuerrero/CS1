// This File is simply for demonstration not compiling.
// Multiple ways to cause a seg fault.

#include <stdio.h>

// 1) Dereferencing an uninitialized pointer. p has garabeg data.

int *p;
*p = 42;

// 2) Dereferencing an NULL  pointer.

int p* = NULL;
*p = 34;

// 3) go so far out of bounds on a array.

int i, array[10];

for (i = 0; i < 10000000000; i++)
  array[i] = 0;

array[10000000001] = 4;

// 4) Going out of bounds in an array can also corrupt a pointer.
int main(void)
{
  int p*= NULL, i, a[100];

  if (p == NULL)
    printf("Initially,p is NULL. \n");

  for (i = 0; i < 1000; i++)
    a[i] = 100087;

  
}
