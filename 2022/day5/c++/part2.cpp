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
         sscanf(line.c_str(), "move %d from %d to %d", &to_move, &from, &to)) {
    deque<char> c_retained_order;
    while (to_move--) {
      c_retained_order.push_front(stacks[from - 1].back());
      stacks[from - 1].pop_back();
    }

    for (const char c : c_retained_order) stacks[to - 1].push_back(c);
  }

  input.close();

  for (const auto &[_, crates] : stacks) cout << crates.back();
  cout << '\n';
}
