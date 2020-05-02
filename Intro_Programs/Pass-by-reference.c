#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_student(char *fname, char *lname, int *ucfid)
{
  // Note the use of %07 to ensure that we print at least 7 digits. If the ID
	// is shorter than 7 digits, the 0 ensures that we pad with zeroes. (E.g.,
	// 123456 is printed as 0123456.)
	//
	// Notice also that we have to dereference ucfid, which is an address. We do
	// not have to dereference lName or fName (even though they are addresses),
	// because printf() expects that the argument corresponding to %s is the
	// base address of the char array.
  printf("%s, %s (UCF ID: %07d)\n", fname, lname ,*ucfid);

  // Because fName is the base address of the first name string, changing
	// fname[0] is going to have effects that are felt back in main()!
  fname[0] = '\0';

  // Here, we might be going out of bounds of the space allocated for lName.
	// That may or may not cause a segmentation fault!
  strcpy(lname,"lulhaxxedlololol");

  // Again, we use the fact that ucfid is an address to go change the value
	// stored there. This new value will be visible from main() when we return.

  *ucfid = 6543210;

}

int main(void)
{
  int n;
  // In class, the question was: What are the data types for these variables?
  char *firstName;
  char *lastName;
  // Making this a pointer is completely unnecessary, but as far as malloc()
	// goes, the more practice you get, the better.
  int *ucfid;
  // Figure out how much space to allocate for the first name string. Notice
	// throughout this program that scanf() wants the ***ADDRESS*** where it
	// should store the data it scans, and that's exactly what it gets every time.
  printf("How many letters are in your first name?");
  scanf("%d", &n);

	// Now allocate space for that name and scan it in. Don't forget to include
	// space for the null sentinel ('\0') at the end of the string!
  firstName = malloc(sizeof(char) * (n + 1));

  printf("What is you your first name ?\n");
  scanf("%s", firstName);
  // Figure out how much space to allocate for the last name string.
  printf("How many letters are in your last name ?");
  scanf("%d", &n);
  // Now allocate space for that name and scan it in.
  lastName = malloc(sizeof(char) * (n + 1));

  printf("What is you your last name ?");
  scanf("%s", lastName);
  // Now allocate space for the numeric student ID and scan it in.
  ucfid = malloc(sizeof(int));
  printf("Enter the numeric portion of your UCF ID:");
  scanf("%d", ucfid);
  // This will print these values, but also change them. Notice that we're
	// passing addresses to the print_student() function. (That's what firstName
	// lastName, and ucfid contain -- addresses!)
  print_student(firstName, lastName, ucfid);
  // Check out how lastName, firstName, and ucfid changed as a result of the
	// print_student() function!
  printf("(Back in main): %s, %s, (UCF ID: %07d)\n", lastName, firstName, *ucfid);


  return 0;

}
