#include <stdio.h>

typedef unsigned long int uint;

/*inputs*/
uint women_count;
uint women[50001];
uint height;



uint find_shorter(uint min, uint max, uint best) {
  uint index, her_height;
  if (min > max || max == -1) {
    return best;
  }
  if (best == height-1) {
    return best;
  }

  index = min + (max-min)/2;
  her_height = women[index];

  if (her_height < height) {
    return find_shorter(index+1, max, her_height > best ? her_height : best);
  }
  return find_shorter(min, index-1, best);
}

uint find_longer(uint min, uint max, uint best) {
  uint index, her_height;
  if (min > max || max == -1) {
    return best;
  }
  if (best == height+1) {
    return best;
  }

  index = min + (max-min)/2;
  her_height = women[index];

  if (her_height > height) {
    return find_longer(min, index-1, her_height < best ? her_height : best);
  }
  return find_longer(index+1, max, best);
}


int main() {
  /*input*/
  uint man_count;


  /*tmp*/
  uint i, res;


  scanf("%lu", &women_count);


  for(i = 0; i < women_count; ++i) {
    scanf("%lu", &women[i]);
  }

  scanf("%lu", &man_count);

  while (man_count--) {
    scanf("%lu", &height);
    res = find_shorter(0, women_count-1, 0);
    if (res == 0) {
      printf("X");
    }
    else {
      printf("%lu", res);
    }
    res = find_longer(0, women_count-1, -1);
    if (res == -1) {
      printf(" X\n");
    }
    else {
      printf(" %lu\n", res);
    }
  }
  return 0;
}






