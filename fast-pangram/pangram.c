#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool ispangram(char *s) {
  unsigned int seen = 0;
  const unsigned int all_letters = (1 << 26) - 1;

  while (*s) {
    char c = *s;
    if (c >= 'A' && c <= 'Z') {
      seen |= (1 << (c - 'A'));
    } else if (c >= 'a' && c <= 'z') {
      seen |= (1 << (c - 'a'));
    }
    s++;
  }

  return seen == all_letters;
}

int main() {
  size_t len;
  ssize_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (ispangram(line))
      printf("%s", line);
  }

  if (ferror(stdin))
    fprintf(stderr, "Error reading from stdin");

  free(line);
  fprintf(stderr, "ok\n");
}
