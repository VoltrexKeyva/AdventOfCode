#include <fstream>
#include <iostream>
#include <string>

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
  while (getline(input, item_list)) {
    const int half_len = item_list.length() / 2;
    const string first_compartment = item_list.substr(0, half_len),
                 second_compartment = item_list.substr(half_len, half_len);

    for (int i = 0; i < first_compartment.length(); i++) {
      const char item = first_compartment[i];

      if (second_compartment.find(item) != string::npos) {
        priority_sum += item - (item < lower_alpha_ascii ? upper_alpha_ascii
                                                         : lower_alpha_ascii);
        break;
      }
    }
  }

  input.close();

  cout << priority_sum << '\n';
}
