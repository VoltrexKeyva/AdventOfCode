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

  size_t total_score = 0;

  string line;
  while (getline(input, line)) {
    const char *c = line.c_str();
    int a = c[0], b = c[2];

    a -= 'A';
    b -= 'X';

    total_score += (4 + b - a) % 3 * 3 + b + 1;
  }

  input.close();

  cout << total_score << '\n';
}
