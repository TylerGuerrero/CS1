// This file doesn't work but is somply for demonstrating purposes.

int i;
int *p = NULL;

if (p != NULL)
  *p = 56;
else
  printf("WARNING! It loos like you forgot to give p a valid integer adress\n");

  // Using printf to tell exaclty where you seg faulted.
  #include <stdio.h>

  int main(void)
  {
    int *p = NULL;

    printf("Attempting to dereference p...");
    *p = 510;

    printf("Successfully dereferenced p! Hooray!");

    return 0;
  }


    #include <stdio.h>

    int main(void)
    {
      int *p = NULL;

      printf("Attempting to dereference p...\n");
      *p = 510;

      printf("Successfully dereferenced p! Hooray!\n");

      return 0;
    }


  /*
  On my system, this doesn't print anything but "Segmentation fault." However,
  the program is still crashing on the *p = 510 line. What's happening here is
  that printf() doesn't actually print stuff to the screen every time you
  call it. Sometimes it takes your text and stores it in a buffer in memory,
  and waits until later to print it all out. If your program crashes before
  printf() decides its buffer is full enough to warrant printing it all to
  your screen, then those statements won't give you an accurate view of
  where, when, and why the program is crashing.

  However, printf() will usually flush out the buffer (i.e., print all the text
  it has been accumulating) if it encounters a newline character (\n). There
  are some exceptions to this, though. One way to be absolutely sure you're
  forcing a flush of the printf() buffer is to call a function called fflush()
  explicitly. That function will tell printf() to flush everything that is
  waiting in its buffer. In particular, we need to flush "stdout"
  (pronounced "standard out"), which is a handle that C provides to the
  place your text is headed. (Usually it's your screen, but sometimes
  it's a file. We'll talk about that another day.)
  */


    #include <stdio.h>

    int main(void)
    {
      int *p = NULL;

      printf("Attempting to dereference p...");
      fflush(stdout);
      *p = 510;

      printf("Successfully dereferenced p! Hooray!");
      fflush(stdout);

      return 0;
    }
