#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::string line;
  std::unordered_multiset<size_t> winning_nums;
  size_t total_points = 0;
  std::string lexeme{};
  while (std::getline(input, line)) {
    const size_t colon_idx = line.find(':');
    size_t num = 0;
    size_t points = 0;
    bool separator_found = false;

    for (size_t i = colon_idx + 2; i < line.size(); i++) {
      const char c = line[i];
      if (std::isdigit(c)) {
        lexeme += c;

        while (i + 1 < line.size() && std::isdigit(line[i + 1]))
          lexeme += line[++i];

        num = std::stoull(lexeme);
        lexeme.clear();

        if (separator_found && winning_nums.find(num) != winning_nums.end())
          points += points == 0 ? 1 : points;
        else
          winning_nums.insert(num);
      } else if (c == '|')
        separator_found = true;
    }

    total_points += points;
    winning_nums.clear();
  }

  std::cout << total_points << std::endl;
}
