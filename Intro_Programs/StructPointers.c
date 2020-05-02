#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Typedef struct student
{
  char *fName;
  char *lName;
  int pid;
} classInfo;

// This is a pass-by-reference version of the function we saw in structs.c.
// Notice that when we have a pointer to a struct, we have two options for
// accessing its members:
//
//    1. Dereference the pointer, then access the members as normal, with the
//       dot operator (.):
//
//       (*s).lName
//
//    2. Use the arrow operator (->) which takes care of the dereferencing for
//       you:
//
//       s->lName

void print_student (classInfo *s)
{
  // The following lines are two ways of achieving the same result:
  printf("%s, %s, (PID 07%d)\n", s->fName, s->lName, s->pid);
  printf("%s, %s, (PID 07%d)\n",(*s).fname,(*s).lname, (*s).pid);
  // Since we're dealing with a pointer this time, notice how this changes
	// the output of main() after we return from this function. Compare this to
	// the result of structs.c.

  s->fName[0] = '\0';
  strcpy(s->lName,"lulhaxxedlololol");
  s->pid = 6543210;

}

int main(void)
{
  int n;
  classInfo *s = malloc(sizeof(classInfo));

  printf("How many letters are in your first name? ");
	scanf("%d", &n);

  s->fName = malloc(sizeof(char) * (n + 1));

  printf("Enter your first name: ");
  scanf("%s", s->fName);

  printf("How many letters are in your last name? ");
  scanf("%d", &n);

  s->lName = malloc(sizeof(char) * (n + 1));

  printf("Enter your first name: ");
  scanf("%s", s->lName);

  printf("Enter your pid");
  scanf("%d", &(s->pid));

  print_student(s);

  printf("%s, %s (PID: %07d)\n", s->lName, s->fName, s->pid);

  // Notice that it wouldn't make sense to free s first, because then we
	// couldn't safely go back into s to free the lName and fName pointers. When
	// dealing with nested dynamic memory allocation, you generally want to free
	// things in the reverse order from which you allocated them. (However, it
	// doesn't matter whether we free s->lName or s->fName first, as long as we
	// free both of them before s itself.)
  free(s->fName);
  free(s->lName);
  free(s);

  return 0;






}
