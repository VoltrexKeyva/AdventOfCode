#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  map<string, size_t> entries;

  vector<string> paths;
  string line;
  while (getline(input, line)) {
    if (line[0] == '$') {
      line.erase(0, 2);

      const int idx = line.find(' ');
      const string command = line.substr(0, idx);

      if (command == "cd") {
        const string dir = line.substr(idx + 1);

        if (dir == "..")
          paths.pop_back();
        else {
          if (paths.empty()) {
            paths.push_back(dir);

            continue;
          }

          ostringstream path;

          copy(paths.begin(), paths.end(), ostream_iterator<string>(path, "/"));
          path << dir;

          paths.push_back(path.str());
        }
      }

      continue;
    }

    const string first_column = line.substr(0, line.find(' '));

    if (first_column == "dir") continue;

    size_t size = stoi(first_column);

    for (const string &path : paths) {
      if (!entries.contains(path)) entries.insert({path, 0});

      entries[path] += size;
    }
  }

  input.close();

  size_t total_size = 0;

  for (const auto &[_, size] : entries)
    if (size <= 100'000) total_size += size;

  cout << total_size << '\n';
}
