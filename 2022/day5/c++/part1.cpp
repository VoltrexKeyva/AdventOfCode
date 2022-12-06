#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  map<int, deque<char>> stacks;

  string line;
  while (getline(input, line) && !line.empty())
    for (int i = 0; i < line.length(); i++) {
      const char c = line[i];

      if (c < 'A' || c > 'Z') continue;

      const int idx = i >> 2;

      if (!stacks.contains(idx)) stacks.insert(pair<int, deque<char>>(idx, {}));
      stacks[idx].push_front(c);
    }

  int to_move, from, to;
  while (getline(input, line) &&
         sscanf(line.c_str(), "move %d from %d to %d", &to_move, &from, &to))
    while (to_move--) {
      stacks[to - 1].push_back(stacks[from - 1].back());
      stacks[from - 1].pop_back();
    }

  input.close();

  for (const auto &[_, crates] : stacks) cout << crates.back();
  cout << '\n';
}
