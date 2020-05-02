#include <stdio.h>
#include <stdlib.h>
// Fibonnaci simply assumes you have two numbers 0 and 1, then keeps adding the
// previous two numbers.Assumes inputs are greater then or equal to 0.

// Big O worst case O(2^n), Best case O(2^n).
int fib(int n)
{
  if (n < 2)
    return n;

  return fib(n - 1) + fib(n - 2);
}

// Big O worst case O(n), Best case O(1). Space complexity O(n).
int fibonacci_optimized(int n)
{
  int i, *array, result;

  if (n < 2)
    return n;

  array = malloc(sizeof(int) * n);
  if (array == NULL)
  {
    printf("Could not allocate memory\n");
    return 0;
  }

  array[0] = 0;
  array[1] = 1;

  for (i = 2; i <= n; i++)
    array[i] = array[i - 1] + array[i - 2];

  result = array[n];
  free(array);

  return result;
}

// Big O Worst case: O(n), Best case O(n). Space Complexity O(1).
int fibonacci_optimized_fancy(int n)
{
  int i, result, array[2];

  if (n < 2)
    return n;

  array[0] = 0;
  array[1] = 1;

  for (i = 2; i <= n; i++)
    array[i % 2] = array[i - 1] + array[i - 2];

  return array[n % 2];
}

// Big O Worst case: O(n), Best case O(n). Space Complexity O(1).
int fibonacci_optimized_fancy_no_array(int n)
{
  int i, result, a, b, c;

  if (n < 2)
    return n;

  a = 0;
  b = 1;

  for (i = 2; i <= n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }

  return b;

}

int main(void)
{
  return 0;
}
