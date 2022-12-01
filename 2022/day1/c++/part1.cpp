#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  size_t most_calories = 0, calories = 0;

  string line;
  while (getline(input, line)) {
    if (line == "") {
      if (calories > most_calories) most_calories = calories;

      calories = 0;
      continue;
    }

    calories += stoi(line);
  }

  input.close();

  cout << most_calories << '\n';
}
