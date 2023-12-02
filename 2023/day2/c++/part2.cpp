#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::string line;
  size_t lowest_red = 0;
  size_t lowest_green = 0;
  size_t lowest_blue = 0;
  size_t total = 0;
  std::string lexeme{};
  while (std::getline(input, line)) {
    const size_t semi_colon_idx = line.find(':');
    size_t num = 0;

    for (size_t i = semi_colon_idx + 2; i < line.size(); i++) {
      const char c = line[i];

      if (std::isdigit(c)) {
        lexeme += c;

        while (std::isdigit(line[i + 1])) lexeme += line[++i];

        num = std::stoull(lexeme);
        lexeme.clear();
      } else if (std::isalpha(c)) {
        switch (c) {
          case 'r':
            if (num > lowest_red) lowest_red = num;
            i += 2;
            break;
          case 'g':
            if (num > lowest_green) lowest_green = num;
            i += 4;
            break;
          case 'b':
            if (num > lowest_blue) lowest_blue = num;
            i += 3;
            break;
        }
      }
    }

    total += lowest_red * lowest_green * lowest_blue;
    lowest_red = 0;
    lowest_green = 0;
    lowest_blue = 0;
  }

  std::cout << total << std::endl;
}
