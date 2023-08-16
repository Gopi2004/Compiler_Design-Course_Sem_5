#include <stdio.h>
int main() {
  /* Get the name of the text file from the user. */
  char filename[1024];
  printf("Enter the name of the text file: ");
  scanf("%s", filename);

  /* Open the text file in read mode. */
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Could not open file: %s\n", filename);
    return 1;
  }

  /* Read the content of the file and print it to the console. */
  char c;
  while ((c = fgetc(f)) != EOF) {
    printf("%c", c);
  }

  /* Close the file. */
  fclose(f);

  return 0;
}