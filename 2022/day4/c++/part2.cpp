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

  size_t overlapping_pairs = 0;

  string pair;
  while (getline(input, pair)) {
    int s1r1, s1r2, s2r1, s2r2;

    sscanf(pair.c_str(), "%d-%d,%d-%d", &s1r1, &s1r2, &s2r1, &s2r2);

    if ((s1r1 <= s2r1 && s1r2 >= s2r1) || (s2r1 <= s1r1 && s2r2 >= s1r1))
      overlapping_pairs++;
  }

  input.close();

  cout << overlapping_pairs << '\n';
}
