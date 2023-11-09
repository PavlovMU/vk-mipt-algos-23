#include <iostream>
#include <stack>

int main() {
  std::string str;
  std::cin >> str;
  std::stack<char> st;
  int n = str.length();
  for (int i = 0; i < n / 2; ++i) {
    st.push(str[i]);
  }
  if (n % 2 == 0) {
    for (int i = n / 2; i < n; ++i) {
      if (str[i] == st.top()) {
        st.pop();
      }
    }
  } else {
    for (int i = n / 2 + 1; i < n; ++i) {
      if (str[i] == st.top()) {
        st.pop();
      }
    }
  }
  std::cout << (st.size() == 0 ? "yes\n" : "no\n");
}
