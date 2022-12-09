#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

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
  vector<position> positions(10);

  fill(positions.begin(), positions.end(), (position){0, 0});

  string line;
  while (getline(input, line)) {
    const char direction = line[0];
    const int steps = stoi(line.substr(line.find(' ') + 1));

    for (int i = 0; i < steps; i++) {
      switch (direction) {
        case 'U':
          positions[0].y++;
          break;
        case 'L':
          positions[0].x--;
          break;
        case 'D':
          positions[0].y--;
          break;
        case 'R':
          positions[0].x++;
      }

      for (int j = 0; j < positions.size() - 1; j++) {
        position &tail = positions[j + 1], &head = positions[j];

        if (abs(tail.x - head.x) > 1 || abs(tail.y - head.y) > 1) {
          const int y = head.y - tail.y, x = head.x - tail.x;

          tail.y += (y > 0) - (y < 0);
          tail.x += (x > 0) - (x < 0);
        }
      }

      tail_positions.insert(to_string(positions[9].x) + "," +
                            to_string(positions[9].y));
    }
  }

  cout << tail_positions.size() << '\n';
}
