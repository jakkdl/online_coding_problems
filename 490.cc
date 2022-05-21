#include <iostream>
#include <vector>

using namespace std;


int main() {
  int maxLen{};
  string line;
  vector<string> words{};

  while(getline(cin, line)) {
    if (static_cast<int>(line.size()) > maxLen) {
      maxLen = line.size();
    }
    words.push_back(line);
  }
  for (int i{}; i < maxLen; ++i) {
    for (int j{static_cast<int>(words.size()) - 1}; j >= 0; --j) {
      if (i < static_cast<int>(words[j].size())) {
        cout << words[j][i];
      }
      else {
        cout << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}


