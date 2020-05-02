#include <stdio.h>

void old_swap(int i, int j)
{
  int temp = i;
  i = j;
  j = temp;
}

void new_swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

int main(void)
{
  int i = 57, j = 34;

  old_swap(i, j);

  printf("i = %d, j = %d\n", i, j);

  new_swap(&i, &j);
  printf("i = %d, j = %d\n", i, j);

    return 0;
}
