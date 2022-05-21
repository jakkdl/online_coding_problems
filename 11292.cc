#include <cstdio>
#include <set>

using namespace std;


int main() {

  multiset<int> heads{}, knights{};
  int head_count, knight_count, tmp, cost;
  bool success;

  while ( scanf("%d%d", &head_count, &knight_count)
      && head_count != 0
      && knight_count != 0) {
    success = true;
    cost = 0;
    heads.clear();
    knights.clear();

    for (int i{}; i < head_count; ++i) {
      scanf("%d", &tmp);
      heads.insert(tmp);
    }

    for (int i{}; i < knight_count; ++i) {
      scanf("%d", &tmp);
      knights.insert(tmp);
    }

    if (knight_count < head_count) {
      printf("Loowater is doomed!\n");
      continue;
    }

    multiset<int>::const_iterator k = knights.cbegin();

    for (int head : heads) {
      while (k != knights.cend() && *k < head) {
        ++k;
      }
      if (k == knights.cend()) {
        printf("Loowater is doomed!\n");
        success = false;
        break;
      }
      cost += *k;
      ++k;
    }
    if (success) {
      printf("%d\n", cost);
    }



  }
  return 0;
}
