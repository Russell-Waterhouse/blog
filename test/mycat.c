#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    puts("Please call this program with exactly one argument, the file you "
         "wish to print");
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");
  if(file == NULL) {
      puts("Error opening that file. Please check that it exists and you have "
           "the correct permissions to access it");
      return EXIT_FAILURE;
  }

  char ch;

  while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
  }

  fclose(file);

  return EXIT_SUCCESS;
}
