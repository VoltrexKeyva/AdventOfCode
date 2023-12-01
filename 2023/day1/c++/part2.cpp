#include <array>
#include <fstream>
#include <iostream>
#include <string>

static constexpr std::array<std::string_view, 9> wnums = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::string line;
  size_t sum = 0;
  size_t* first = nullptr;
  size_t last = 0;
  while (std::getline(input, line)) {
    for (size_t i = 0; i < line.size(); i++) {
      const std::string& sliced = line.substr(i);
      size_t num = 0;

      if (std::isdigit(sliced[0]))
        num = sliced[0] - '0';
      else
        for (size_t j = 0; j < wnums.size(); j++)
          if (sliced.starts_with(wnums[j])) {
            num = j + 1;
            break;
          }

      if (num != 0) {
        if (first == nullptr) {
          first = new size_t(num);
        } else {
          last = num;
        }
      }
    }

    if (last == 0) last = *first;

    sum += *first * 10 + last;

    delete first;
    first = nullptr;
    last = 0;
  }

  input.close();

  std::cout << sum << std::endl;
}
