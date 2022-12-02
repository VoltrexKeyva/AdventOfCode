#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum Shapes {
  ROCK_OP = 'A',
  ROCK = 'X',
  PAPER_OP = 'B',
  PAPER = 'Y',
  SCISSORS_OP = 'C',
  SCISSORS = 'Z'
};

int get_shape_score(const char move) {
  return move == Shapes::ROCK ? 1 : move == Shapes::PAPER ? 2 : 3;
}

int get_score(const char move1, const char move2) {
  int score = get_shape_score(move2);

  if ((move1 == Shapes::ROCK_OP && move2 == Shapes::ROCK) ||
      (move1 == Shapes::PAPER_OP && move2 == Shapes::PAPER) ||
      (move1 == Shapes::SCISSORS_OP && move2 == Shapes::SCISSORS))
    score += 3;
  else if ((move1 == Shapes::ROCK_OP && move2 == Shapes::PAPER) ||
           (move1 == Shapes::PAPER_OP && move2 == Shapes::SCISSORS) ||
           (move1 == Shapes::SCISSORS_OP && move2 == Shapes::ROCK))
    score += 6;

  return score;
}

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  size_t total_score = 0;

  string line;
  while (getline(input, line)) total_score += get_score(line.at(0), line.at(2));

  input.close();

  cout << total_score << '\n';
}
