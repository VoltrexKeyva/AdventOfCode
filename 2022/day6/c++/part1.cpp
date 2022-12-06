#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

#define START_OF_PACKET_LEN 4

int main() {
  ifstream input("../input.txt");

  if (!input.is_open()) {
    cerr << "Unable to open input file\n";

    return 1;
  }

  size_t chars_processed = START_OF_PACKET_LEN;

  string datastream_buf;
  getline(input, datastream_buf);

  input.close();

  for (int i = 0; i < datastream_buf.length(); i++, chars_processed++) {
    const string charset = datastream_buf.substr(i, START_OF_PACKET_LEN);
    const set<char> unique_charset(charset.begin(), charset.end());

    if (unique_charset.size() == START_OF_PACKET_LEN) break;
  }

  cout << chars_processed << '\n';
}
