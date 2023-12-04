#include <fstream>
#include <iostream>
#include <string>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14
#define AFTER_GAME_IDENTIFIER 5

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::string line;
  size_t possible_games = 0;
  std::string lexeme{};
  while (std::getline(input, line)) {
    const size_t colon_idx = line.find(':');
    size_t red = 0;
    size_t green = 0;
    size_t blue = 0;
    size_t num = 0;
    bool impossible = false;

    for (size_t i = colon_idx + 2; i < line.size(); i++) {
      const char c = line[i];

      if (std::isdigit(c)) {
        lexeme += c;

        while (std::isdigit(line[i + 1])) lexeme += line[++i];

        num = std::stoull(lexeme);
        lexeme.clear();
      } else if (std::isalpha(c)) {
        switch (c) {
          case 'r':
            red += num;
            i += 2;
            break;
          case 'g':
            green += num;
            i += 4;
            break;
          case 'b':
            blue += num;
            i += 3;
            break;
        }
      }

      if (c == ';' || i >= line.size() - 1) {
        if (red > MAX_RED || green > MAX_GREEN || blue > MAX_BLUE) {
          impossible = true;
          break;
        }

        red = 0;
        green = 0;
        blue = 0;
      }
    }

    if (!impossible)
      possible_games += std::stoull(line.substr(
          AFTER_GAME_IDENTIFIER, colon_idx - AFTER_GAME_IDENTIFIER));
  }

  std::cout << possible_games << std::endl;
}
