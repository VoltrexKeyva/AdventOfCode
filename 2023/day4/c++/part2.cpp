#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#define AFTER_CARD_IDENTIFIER 5

int main() {
  std::ifstream input("../input.txt");

  if (!input.is_open()) {
    std::cerr << "Could not open input.txt" << std::endl;

    return 1;
  }

  std::string line;
  std::unordered_multiset<size_t> winning_nums;
  std::unordered_map<size_t, size_t> copies;
  size_t total_scratchcards = 0;
  std::string lexeme{};
  while (std::getline(input, line)) {
    const size_t colon_idx = line.find(':');
    size_t num = 0;
    size_t matching_nums = 0;
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
          matching_nums++;
        else
          winning_nums.insert(num);
      } else if (c == '|')
        separator_found = true;
    }

    const size_t card_num = std::stoull(
        line.substr(AFTER_CARD_IDENTIFIER, colon_idx - AFTER_CARD_IDENTIFIER));
    const bool is_new_card = copies.find(card_num) == copies.end();
    const size_t repeat = is_new_card ? 1 : copies[card_num] + 1;

    for (size_t i = 0; i < matching_nums; i++) {
      const bool is_new = copies.find(card_num + i + 1) == copies.end();
      copies.insert_or_assign(
          card_num + i + 1,
          is_new ? repeat : copies[card_num + i + 1] + repeat);
    }

    matching_nums *= is_new_card ? 1 : copies[card_num] + 1;
    copies.erase(card_num);

    total_scratchcards += matching_nums + 1;
    winning_nums.clear();
  }

  std::cout << total_scratchcards << std::endl;
}
