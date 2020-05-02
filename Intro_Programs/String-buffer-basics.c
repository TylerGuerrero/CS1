#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int i;
  // Restrict the filename to 20 chars.
  char filename[21];
  // Restrict the buffer to 800 chars.
  char buffer[801];

  char *word;

  FILE *ifp = NULL;

  printf("%d", i = 17);

  strcpy(filename,"input.txt");

  if (ifp = fopen(filename, "r") == NULL)
  {
    fprintf(stderr, "Could not open %s in main()\n", filename);
    exit(0); 
  }

  while(fscanf(ifp, "%s", buffer) != EOF)
  {
    word = malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(word, buffer);
    printf("Read the string %s\n", word);
    free(word);
  }

  fclose(ifp);
  ifp = NULL;

  return 0;

}
