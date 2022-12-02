#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum Shapes { ROCK = 'A', PAPER = 'B', SCISSORS = 'C' };

int get_shape_score(const char move) {
  return move == Shapes::ROCK ? 1 : move == Shapes::PAPER ? 2 : 3;
}

int get_score(const char move, const char outcome) {
  switch (outcome) {
    case 'X':  // Lose
      return get_shape_score(move == Shapes::ROCK    ? Shapes::SCISSORS
                             : move == Shapes::PAPER ? Shapes::ROCK
                                                     : Shapes::PAPER);
    case 'Y':  // Draw
      return get_shape_score(move) + 3;
    case 'Z':  // Win
      return get_shape_score(move == Shapes::ROCK    ? Shapes::PAPER
                             : move == Shapes::PAPER ? Shapes::SCISSORS
                                                     : Shapes::ROCK) +
             6;
    default:  // Unknown
      return 0;
  }
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
