#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char input[2];
  unsigned long int malloc_size = 10;
  char *malloc_buf = malloc(malloc_size);

  while (1) {
    printf("Guess the random number:\n");
    read(0, input, 2);
    input[1] = '\0';
    printf("%s\n", input);

    unsigned long int new_malloc_size = malloc_size * 4;
    char *new_alloc = realloc(malloc_buf, malloc_size + new_malloc_size);

    while (!new_alloc) {
      new_malloc_size /= 2;
      printf("Trying %ld\n", malloc_size + new_malloc_size);
      new_alloc = realloc(malloc_buf, malloc_size + new_malloc_size);
    }

    malloc_buf = new_alloc;
    malloc_size += new_malloc_size;
    memset(malloc_buf, 1, malloc_size);

    printf("Alloc'd %ld bytes\n", malloc_size);
  }
}
