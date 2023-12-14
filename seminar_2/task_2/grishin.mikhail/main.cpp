#include <stack>

bool is_palindrome(std::string s) {
  std::stack<char> st;
  for (auto i : s) {
    st.push(i);
  }
  for (auto i : s) {
    auto temp = st.top();
    st.pop();
    if (i != temp) {
      return false;
    }
  }
  return true;
}
