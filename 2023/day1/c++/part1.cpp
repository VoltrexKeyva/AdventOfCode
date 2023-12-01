#include <fstream>
#include <iostream>
#include <string>

constexpr std::string_view nums = "0123456789";

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::string line;
  size_t sum = 0;
  while (std::getline(input, line))
    sum += std::stoull(line.substr(line.find_first_of(nums), 1) +
                       line.substr(line.find_last_of(nums), 1));

  input.close();

  std::cout << sum << std::endl;
}
