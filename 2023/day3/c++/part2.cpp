#include <fstream>
#include <iostream>
#include <string>
#include <vector>

size_t consume_bidinum(const std::vector<std::string>& lines, size_t i,
                       size_t j, size_t* visible_len = nullptr) {
  const std::string& line = lines[i];
  size_t start = j;
  size_t end = j;

  if (j != 0)
    while (start > 0 && std::isdigit(line[start - 1])) start--;
  if (j + 1 != line.size())
    while (end < line.size() && std::isdigit(line[end + 1])) end++;

  if (visible_len != nullptr) *visible_len = end - j;

  return std::stoull(line.substr(start, end - start + 1));
}

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

  size_t total_gear_ratio = 0;
  for (size_t i = 0; i < lines.size(); i++) {
    const std::string& line = lines[i];
    for (size_t j = 0; j < line.size(); j++) {
      const char c = line[j];
      std::vector<size_t> nums;

      if (c == '*') {
        if (j != 0 && std::isdigit(line[j - 1]))
          nums.push_back(consume_bidinum(lines, i, j - 1));
        if (j + 1 != line.size() && std::isdigit(line[j + 1]))
          nums.push_back(consume_bidinum(lines, i, j + 1));

        if (nums.size() != 2) {
          const size_t start = j == 0 ? j : j - 1;
          const size_t end = j + 2 > line.size() ? j + 1 : j + 2;
          size_t* len = new size_t;

          if (i != 0)
            for (size_t k = start; k < end; k++)
              if (std::isdigit(lines[i - 1][k])) {
                nums.push_back(consume_bidinum(lines, i - 1, k, len));
                k += *len;
              }

          if (i + 1 != lines.size())
            for (size_t k = start; k < end; k++)
              if (std::isdigit(lines[i + 1][k])) {
                nums.push_back(consume_bidinum(lines, i + 1, k, len));
                k += *len;
              }

          delete len;
        }

        if (nums.size() != 2) continue;

        total_gear_ratio += *nums.begin() * *nums.rbegin();
      }
    }
  }

  std::cout << total_gear_ratio << std::endl;
}
