#include <stdio.h>
#include <ctype.h>
#include <math.h>




int main() {
  char table[10000];
  int len, width, case_count, i, case_current;
  char c, success;

  scanf("%d%*c", &case_count);

  for(case_current = 1; case_current <= case_count; ++case_current) {
    printf("Case #%d:\n", case_current);
    len = 0;
    success = 1;

    while (scanf("%c", &c) && c != '\n') {
      if (isalpha(c)) {
        table[len] = c;
        ++len;
      }
    }
    width = sqrt(len);
    if (len != width*width) {
      printf("No magic :(\n");
      continue;
    }
    for (i = 0; i < (len+1)/2; ++i) {
      int col = i%width;
      int row = i/width;

      /* [col, row] == [row, col] == [width-row, width-col] == [width-col, width-row]*/
      c =      table[col               + width * row];

      if (c != table[row               + width * col] ||
          c != table[(width - col - 1) + width * (width - row - 1)] ||
          c != table[(width - row - 1) + width * (width - col - 1)]) {
        printf("No magic :(\n");
        success = 0;
        break;
      }
    }
    if (success) {
      printf("%d\n", width);
    }


  }
  return 0;
}
