#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main(void)
{
  int i, n;

  char filename[32];
  char buffer[1024];

  char **strings;

  FILE *ifp;

  if (ifp = fopen("input.txt", "r") == NULL)
  {
    fprinf(stderr,"Failed to open input files\n");
    exit(0);
  }

  fscanf(ifp, "%d", &n);

  strings = malloc(sizeof(char*) * n);

  for (i = 0; i < n; i++)
  {
    fscanf(ifp, "%s", buffer);
    strings[i] = malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(strings[i], buffer);
    printf("The string from the file = %s\n", strings[i]);
  }

  for (i = 0; i < n; i++)
  {
    printf("strings[%d] = %s is being deleted\n", i, strings[i]);
    free(strings[i]);
  }

  free(strings);
  fclose(ifp);
  return 0;

}
