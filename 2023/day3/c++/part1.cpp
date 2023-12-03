#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define IS_SYMBOL(c) (c != '.' && !std::isdigit(c))

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::vector<std::string> lines;
  {
    std::string line;
    while (std::getline(input, line)) lines.push_back(line);
  }

  size_t sum = 0;
  std::string lexeme{};
  for (size_t i = 0; i < lines.size(); i++) {
    const std::string& line = lines[i];
    for (size_t j = 0; j < line.size(); j++) {
      const size_t start = j;
      const char c = line[j];
      bool adjacent = false;

      if (!std::isdigit(c)) continue;

      lexeme += c;

      while (j + 1 < line.size() && std::isdigit(line[j + 1]))
        lexeme += line[++j];

      if (start != 0 && IS_SYMBOL(line[start - 1])) adjacent = true;
      if (!adjacent && j + 1 < line.size() && IS_SYMBOL(line[j + 1]))
        adjacent = true;

      if (!adjacent) {
        const bool not_first = i != 0;
        const bool not_last = i != lines.size() - 1;

        for (size_t k = start == 0 ? start : start - 1;
             k < (j + 2 > line.size() ? j + 1 : j + 2); k++)
          if ((not_first && IS_SYMBOL(lines[i - 1][k])) ||
              (not_last && IS_SYMBOL(lines[i + 1][k]))) {
            adjacent = true;
            break;
          }
      }

      if (adjacent) sum += std::stoull(lexeme);

      lexeme.clear();
    }
  }

  std::cout << sum << std::endl;
}
