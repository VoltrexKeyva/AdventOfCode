#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int lower_alpha_ascii = 'a' - 1, upper_alpha_ascii = 'A' - 27;

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  size_t priority_sum = 0;

  string item_list;
  vector<string> group;
  while (getline(input, item_list)) {
    group.push_back(item_list);

    if (group.size() != 3) continue;

    for (int i = 0, count = 1; i < 3; i++) {
      const string item_list_ = group[i];

      for (int j = 0; j < item_list_.length(); j++) {
        const char item = item_list_[j];

        for (int m = 0; m < 3; m++) {
          if (i == m) continue;
          if (group[m].find(item) == string::npos) break;

          count++;
        }

        if (count == 3) {
          priority_sum += item - (item < lower_alpha_ascii ? upper_alpha_ascii
                                                           : lower_alpha_ascii);
          break;
        }

        count = 1;
      }

      if (count == 3) break;
    }

    group.resize(0);
  }

  input.close();

  cout << priority_sum << '\n';
}
