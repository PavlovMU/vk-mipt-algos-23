#include <iostream>

int main() {
  std::string str1;
  std::string str2;
  std::cin >> str1 >> str2;
  int i = 0, j = 0;
  int n = str1.length(), m = str2.length();
  while (i < n && j < m) {
    if (str1[i] == str2[j]) {
      i++;
    }
    j++;
  }
  std::cout << (i == n ? "yes\n" : "no\n");
}
