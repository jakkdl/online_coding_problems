#include <stdio.h>


int stacks[51];
int stack_count;


int main() {
  int sum, stack, moves, set_count = 1, i;

  while (scanf("%i", &stack_count) && stack_count != 0) {
    sum = 0;
    moves = 0;
    for (i=0; i < stack_count; ++i) {
      scanf("%i", &stack);
      sum += stack;
      stacks[i] = stack;
    }
    sum /= stack_count;

    for (i=0; i < stack_count; ++i) {
      moves += stacks[i] > sum ? stacks[i] - sum : 0;
    }

    printf("Set #%d\nThe minimum number of moves is %d.\n\n", set_count, moves);
    ++set_count;
  }
  return 0;
}



