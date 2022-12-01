#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  vector<size_t> all_calories;

  string line;
  size_t calories = 0;
  while (getline(input, line)) {
    if (line == "") {
      all_calories.push_back(calories);

      calories = 0;
      continue;
    }

    calories += stoi(line);
  }

  sort(all_calories.begin(), all_calories.end(), greater<size_t>());
  all_calories.resize(3);

  size_t most_calories_top3 = reduce(all_calories.begin(), all_calories.end());

  cout << most_calories_top3 << '\n';
}
