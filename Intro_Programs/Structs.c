#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// A struct is basically a new data type that bundles up all kinds of individual
// pieces of data (called "fields" or "members" of the struct) into a neat
// little package. This makes it really easy to keep together strongly
// associated pieces of data, and also helps reduce the number of arguments
// we have to pass to some of our functions.
//
// Notice the typedef syntax. We are taking the struct student { ... }
// definition and making 'student' a synonym for it. Now, instead of typing
// "struct student" to create a variable of this type, we can just type
// "student".
typedef struct student
{
	char *fName;
	char *lName;
	int pid;
} classInfo;  // Just because we have "struct student" doesn't mean that I had to
            // use "student" here. I could have typedef'ed this as something
            // crazy like "my_fave_struct".

// Diffenert way of declaring a struct but the top one is prefered.

/* struct student
{
  char *fName;
  char lName;
  int pid;
};


*/
// This is a pass-by-value function. It creates a new copy of 's' in memory.
// All the contents of main's student "s" are copied into this new student
// struct. Because we're copying some string addresses into here, we're able to
// use them to modify the strings held in main's student struct. However, we are
// not able to change the pid that resides back in main's student struct.
//
// More clearly (perhaps), here's a diagram of what's happening in memory when
// print_student() is called initially:
//
// main()                   print_student()
// +-----------------+      +-----------------+
// | s               |      | s               |
// | +-------------+ |      | +-------------+ |
// | | fName       | |      | | fName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x86 |    | |      | | | 0x86 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | lName       | |      | | lName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x98 |    | |      | | | 0x98 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | pid         | |      | | pid         | |
// | | +---------+ | |      | | +---------+ | |
// | | | 1234567 | | |      | | | 1234567 | | |
// | | +---------+ | |      | | +---------+ | |
// | +-------------+ |      | +-------------+ |
// +-----------------+      +-----------------+
//
//  0x86                    0x98
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//  | S | e | a | n |\0 |   | S | z | u | m | l | a | n | s | k | i |\0 |
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//
//   NOTE: Memory boxes not drawn to scale. ;)
//
//
// Then, AFTER the last three lines of the function, right before returning to
// main(), we have this:
//
// main()                   print_student()
// +-----------------+      +-----------------+
// | s               |      | s               |
// | +-------------+ |      | +-------------+ |
// | | fName       | |      | | fName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x86 |    | |      | | | 0x86 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | lName       | |      | | lName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x98 |    | |      | | | 0x98 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | pid         | |      | | pid         | |
// | | +---------+ | |      | | +---------+ | |
// | | | 1234567 | | |      | | | 6543210 | | |
// | | +---------+ | |      | | +---------+ | |
// | +-------------+ |      | +-------------+ |
// +-----------------+      +-----------------+
//
//  0x86                    0x98
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//  |\0 | e | a | n |\0 |   | l | u | l | h | a | x | x | e | d | l | o | l o l o l \0
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//                                                                             ^ LOL!
//                                                           You're in big trouble now!
//
// Notice that the string addresses within the struct allowed print_student()
// to modifiy the strings! However, the pid in main's copy of the struct was
// *not* modified, since we don't have a pointer to it.

void print_student(classInfo s)
{
  printf("%s, %s, (PID %07d%)\n", s.lName, s.fName. s.pid);

  s.fname[0] = '\0';
  strcpy(s.lName, "lulhaxxedlololol");
  s.pid = 6543210;
}



int main(void)
{
  int n;
  classInfo s;

  printf("How many letters are in your first name? ");
  scanf("%d", &n);

  s.fname = malloc(sizeof(char) * (n + 1));

  printf("Enter your first name:");
  scanf("%s", s.fName);

  printf("How many letters are in your first name? ");
  scanf("%d", &n);

  s.lName = malloc(sizeof(char) * (n + 1));

  printf("Enter your last name:");
  scanf("%s", s.lName);

  printf("Enter your pid");
  scanf("%d", &(s.pid));

  print_student(s);

  printf("%s, %s,(PID %07d)\n", s.fName, s.lName, s.pid);
  printf("\nNotice the PID did not change, but the first and last name did!");
	printf("\nWhy is that?\n");

return 0;






}
