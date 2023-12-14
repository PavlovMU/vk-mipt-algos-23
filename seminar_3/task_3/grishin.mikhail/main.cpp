#include <string>

char extra_letter(string a, string b) {
  hashMapB = map[string] int;

  std::unordered_map<char, int> hashMapB;

  for (int i = 0; i < b.size(); ++i) {
    ++hashMapB[b[i]];
  }

  for (int i = 0; i < a.size(); ++i) {
    --hashMapB[a[i]];
  }

  for (const std::pair<char, int> i : hashMapB) {
    if (i.second > 0) {
      return i.first;
    }
  }

  return '';
}
