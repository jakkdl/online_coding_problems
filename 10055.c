#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned long us, them;

  while (scanf("%lu%lu", &us, &them) != EOF) {
    printf("%lu\n", them > us ? them-us : us-them);
  }
  return 0;
}
