#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

struct position {
  int x;
  int y;
};

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  set<string> tail_positions{"0,0"};
  position head{0, 0}, tail{0, 0};

  string line;
  while (getline(input, line)) {
    const char direction = line[0];
    const int steps = stoi(line.substr(line.find(' ') + 1));

    for (int i = 0; i < steps; i++) {
      switch (direction) {
        case 'U':
          head.y++;
          break;
        case 'L':
          head.x--;
          break;
        case 'D':
          head.y--;
          break;
        case 'R':
          head.x++;
      }

      if (abs(tail.x - head.x) > 1 || abs(tail.y - head.y) > 1) {
        const int y = head.y - tail.y, x = head.x - tail.x;

        tail.y += (y > 0) - (y < 0);
        tail.x += (x > 0) - (x < 0);
      }

      tail_positions.insert(to_string(tail.x) + "," + to_string(tail.y));
    }
  }

  cout << tail_positions.size() << '\n';
}
