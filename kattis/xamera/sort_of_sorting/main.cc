#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


bool compare_names(string const& lhs, string const& rhs) {
    return lhs.at(0) < rhs.at(0)
        or (lhs.at(0) == rhs.at(0) and lhs.at(1) < rhs.at(1));
}


int main() {
    int name_count{};
    bool begin{true};
    vector<string> names(200);

    while (cin >> name_count && name_count != 0) {
        if (!begin) {
            cout << endl;
        }
        begin = false;


        for (int i{}; i < name_count; ++i) {
            cin >> names.at(i);
        }

        stable_sort(names.begin(), names.begin()+name_count, compare_names);

        for (int i{}; i < name_count; ++i) {
            cout << names.at(i) << endl;
        }
    }

    return 0;
}
