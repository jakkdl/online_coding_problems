#include <stdio.h>

unsigned int rev(unsigned int original) {
  unsigned int res = 0;
  while (original > 0) {
    res = res * 10 + original % 10;
    original /= 10;
  }
  return res;
}




int main() {
  int case_count;
  int iterations;
  unsigned int original, reverse;

  for (scanf("%i", &case_count); case_count > 0; --case_count) {
    scanf("%u", &original);
    iterations = 0;
    while (1) {
      reverse = rev(original);
      if (reverse == original) {
        break;
      }
      original += reverse;
      ++iterations;
    }
    printf("%i %u\n", iterations, original);
  }
  return 0;
}



  
