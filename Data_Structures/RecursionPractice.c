#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND_VAL 60

int sum(int n)
{
  if (n == 0)
    return 0;

  return n + sum(n - 1);
}

int min(int a, int b)
{
  return (a < b) ? a : b;
}

int find_min_array(int *array, int n)
{
  if (array == NULL || n == 0)
    return 0;

  if (n == 1)
    return array[0];

  return min(array[n - 1], find_min_array(array, n - 1));
}

int find_min_array_fancy(int *array, int n)
{
  if (array == NULL || n == 0)
    return 0;

  if (n == 1)
    return array[0];

  return min(array[0], find_min_array_fancy(array + 1, n - 1));
}

int find_min_array_super_fancy(int *array, int n)
{
  return (n == 1 ? array[0] : find_min_array_super_fancy(array + 1, n - 1));
}

int factorial(int n)
{
  if (n == 0)
    return 1;

  return n * factorial(n - 1);
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int find_max_array(int *array, int n)
{
  if (array == NULL || n == 0)
    return 0;

  if (n == 1)
    return array[0];

  return max(array[n - 1], find_max_array(array, n - 1));
}

int find_max_array_fancy(int *array, int n)
{
  if (array == NULL || n == 0)
    return 0;

  if (n == 1)
    return array[0];

  return max(array[0], find_max_array_fancy(array + 1, n - 1));
}

int find_max_array_super_fancy(int *array, int n)
{
  return (n == 1 ? array[n - 1] : find_max_array_fancy(array, n - 1));
}

int mult(int a, int b)
{
  if (a == 0 || b == 0)
    return 0;

  return a + mult(a, b - 1);
}

void print_string(char *str, int n)
{
  if (str == NULL || n == 0)
  {
    printf("\n");
    return;
  }

  printf("%c", str[0]);
  print_string(str + 1, n - 1);
}

void print_string_alternative(char *str, int n)
{
  if (str == NULL || n == 0)
  {
    printf("\n");
    return;
  }

  print_string_alternative(str, n - 1);
  printf("%c", str[n - 1]);
}

void print_string_fancy(char *str)
{
  if (str == NULL || *str == '\0')
  {
    printf("\n");
    return;
  }

  printf("%c", *str);
  print_string_fancy(str + 1);
}

void print_string_reverse(char *str, int n)
{
  if (str == NULL || n == 0)
  {
    printf("\n");
    return;
  }

  printf("%c", str[n - 1]);
  print_string_reverse(str, n - 1);

}

void print_string_reverse_fancy(char *str, int n, int len)
{
  if (str == NULL || n == 0)
    return;

  print_string_reverse_fancy(str + 1, n - 1, len);
  printf("%c", *str);

  if (n == len)
    printf("\n");
}

unsigned int power(int a, int n)
{
  if (a == 0)
    return 0;

  if (n == 0)
    return 1;

  return a * power(a, n - 1);
}


unsigned int super_fancy_power(int a, int n)
{
  int result;

  if (a == 0)
    return 0;

  if (n == 0)
    return 1;

  result = super_fancy_power(a, n / 2);
  return result * result * ((n % 2 == 0) ? 1 : a);


}

int sumDigit(int n)
{
  if (n == 0)
    return 0;

  return (n % 10) + sumDigit(n / 10);
}

int recursive_binary_search(int *array, int lo, int hi, int key)
{
  int mid;

  if (array == NULL)
    return 0;

  if (lo > hi)
    return 0;

  mid = lo + (hi - lo) / 2;

  if (key < array[mid])
    return recursive_binary_search(array, lo, mid - 1, key);
  else if (key > array[mid])
    return recursive_binary_search(array, mid - 1, hi, key);
  else
    return 1;

}

int *create_array(int n)
{
  int i;
  int *array;

  if (n <= 0)
    return NULL;

  array = malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
    array[i] = rand() % MAX_RAND_VAL + 1;

  return array;
}

int main(void)
{
  return 0;
}
