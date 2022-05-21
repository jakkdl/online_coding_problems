#include <cstdio>
#include <set>
#include <vector>
#include <list>

using namespace std;

class coin {
  public:

    coin(int r, int e) : r{r}, e{e} {};

    coin operator+(coin& rhs) {
      return coin{r + rhs.r, e + rhs.e};
    };
    bool operator<(const coin& other) const {
      return r < other.r || (r == other.r && e < other.e);
    };

    int value() {
      return r*r + e*e;
    };

    int r, e;
};

class result {
  public:
    result(int a, int b, int c) : v{a,b}, c{c} {};
    result(const coin & v, int c) : v{v}, c{c} {};



    coin v;
    int c;
};

int main() {
  //input variables
  int problem_count, coin_count, target;

  //containers
  vector<coin> coins;
  list<result> possibilities;
  set<coin> calculated;

  //temp
  int x, y, v;
  result current{0, 0, 0};

  scanf("%i", &problem_count);
start:
  while (problem_count--) {
    coins.clear();
    possibilities.clear();
    calculated.clear();


    scanf("%i%i", &coin_count, &target);
    target = target * target;
    while (coin_count--) {
      scanf("%i%i", &x, &y);
      coins.push_back(coin{x,y});
    }


    possibilities.push_back(result{0,0,0});

    while (not possibilities.empty()) {
      current = possibilities.front();
      possibilities.pop_front();

      for (coin c : coins) {
        coin tmp{current.v + c};
        v = tmp.value();

        if (v < target) {
          if (calculated.find(tmp) == calculated.end()) {
            possibilities.push_back(result{tmp, current.c+1});
            calculated.insert(tmp);
          }
        }
        else if (v == target) {
          printf("%i\n", current.c+1);
          goto start;
        }



      }
    }
    printf("not possible\n");
  }
  return 0;
}
