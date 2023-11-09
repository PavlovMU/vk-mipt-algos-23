#include <iostream>
#include <queue>
#include <string>

bool isSubsequence(const std::string& a, const std::string& b) {
  std::queue<char> Q;
  for (auto el : a) {
    Q.push(el);
  }
  for (auto el : b) {
    if (Q.front() == el) {
      Q.pop();
    }
  }
  return Q.size() == 0;
}

int main() {
  
}