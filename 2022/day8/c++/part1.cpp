#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  vector<vector<int>> grid;

  string line;
  for (int i = 0; getline(input, line); i++) {
    grid.push_back(vector<int>());

    for (int j = 0; j < line.length(); j++) grid[i].push_back(line[j] - '0');
  }

  size_t visible_trees = grid[0].size() + grid.back().size();

  const size_t size = grid.size();
  for (int i = 1; i < size - 1; i++) {
    const vector<int> heights = grid[i];
    const size_t h_size = heights.size();

    visible_trees += 2;

    for (int j = 1; j < h_size - 1; j++) {
      const int height = heights[j];

      bool v_up = true, v_left = true, v_down = true, v_right = true;

      for (int m = i - 1; m >= 0; m--)
        if (height <= grid[m][j]) {
          v_up = false;

          break;
        }

      for (int m = j - 1; m >= 0; m--)
        if (height <= heights[m]) {
          v_left = false;

          break;
        }

      for (int m = i + 1; m < size; m++)
        if (height <= grid[m][j]) {
          v_down = false;

          break;
        }

      for (int m = j + 1; m < h_size; m++)
        if (height <= heights[m]) {
          v_right = false;

          break;
        }

      if (v_up || v_left || v_down || v_right) visible_trees++;
    }
  }

  cout << visible_trees << '\n';
}
