// Conversion charaters in C.
// %p - for pointers, displays the address.
// %d - for intgers, displays a int.
// %f - for double and float, display a double or float.
// %c - for charaters, displays a char.
// %s - for strings, displays a string.

// And operator. In C every variable has a memory address.
// To access the memory address you can the and operator. &.

// int *p, q, **r; -- int single pointer, int, int double pointer
// int* p, q, * r; -- int single pointer, int, int single pointer.
// int *p, *q, r; -- int single pointer, int single pointer, int.


// char* p, **q, r; -- char single pointer, char double pointer, char.
// char p, *r, q; -- char, char single pointer, char.
// char** p, r,* q; -- char double pointer, char, char single pointer.


// Pointers
// single pointer = wants the address of a primitive type.
// double pointer = wants the address of a single pointer.
// triple pointer = wants the address of a double pointer.


// Dereferencing
// 1 dereference * only does the operation once.
// 2 dereferences ** does the operation twice.

#include <stdio.h>

int main(void)
{
  int i = 52;
  int *p;

  p = &i;

  printf("Value i : %d\n", i);
  printf("Value p : %p\n", p);
  printf("Value &i : %p\n", &i);
  printf("Value &p: %p\n", &p);

  *p = 43;

  printf("Value of i after it has been dereferenced: %d\n\n", i);

  char a = 'a';
  char *b;

  b = &a;

  printf("Value a : %c\n", a);
  printf("Value b : %p\n", b);
  printf("Value &a : %p\n", &a);
  printf("Value &b : %p\n", &b);

  *b = 'z';

  printf("Value of a after it has been dereferenced %c\n", a);

  return 0;

}
