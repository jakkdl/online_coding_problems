#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int entropy(const string & word) {
  int c{}, g{}, t{}, sum{};
  for (char w : word) {
    switch (w) {
      case 'T':
        ++t;
        break;
      case 'G':
        ++g;
        sum += t;
        break;
      case 'C':
        ++c;
        sum += t + g;
        break;
      default:
        sum += t + g + c;
    }
  }
  return sum;
}

bool compare(const string & word1, const string & word2) {
  return entropy(word1) < entropy(word2);
}



int main() {
  int dataset_count, string_count;
  string word;
  vector<string> words{};
  bool print{false};

  for (scanf("%i", &dataset_count); dataset_count > 0; --dataset_count) {
    words.clear();

    if (print) {
      cout << endl;
    }



    scanf("%*i%i", &string_count);

    for (;string_count > 0; --string_count) {
      cin >> word;
      words.push_back(word);
    }

    stable_sort(words.begin(), words.end(), compare);

    for (const string & word : words) {
      cout << word << '\n';
    }
    print = true;
    //cout << endl;
  }
  return 0;
}


