#include <iostream>
#include <string>
#include <stack>

bool isPalindrome(const std::string& a) {
  std::stack<char> stack;
  for (auto el : a) {
    stack.push(el);
  }
  for (auto el : a) {
    if (el != stack.top()) {
      return false;
    }
  }
  return true;
}

int main() {
}