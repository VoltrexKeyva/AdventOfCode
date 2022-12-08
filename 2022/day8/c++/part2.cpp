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

  size_t highest_scenic_score = 0;

  const size_t size = grid.size();
  for (int i = 0; i < size; i++) {
    const vector<int> heights = grid[i];
    const size_t h_size = heights.size();

    for (int j = 0; j < h_size; j++) {
      const int height = heights[j];

      size_t d_up = 0, d_left = 0, d_down = 0, d_right = 0;

      for (int m = i - 1; m >= 0; m--) {
        d_up++;

        if (height <= grid[m][j]) break;
      }

      for (int m = j - 1; m >= 0; m--) {
        d_left++;

        if (height <= heights[m]) break;
      }

      for (int m = i + 1; m < size; m++) {
        d_down++;

        if (height <= grid[m][j]) break;
      }

      for (int m = j + 1; m < h_size; m++) {
        d_right++;

        if (height <= heights[m]) break;
      }

      const size_t scenic_score = d_up * d_left * d_down * d_right;

      if (scenic_score > highest_scenic_score)
        highest_scenic_score = scenic_score;
    }
  }

  cout << highest_scenic_score << '\n';
}
