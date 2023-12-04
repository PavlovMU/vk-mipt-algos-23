#include <iostream>
#include <string>

int main() {
    std::string s;
    std::string t;
    std::cin >> s >> t;
    int s_len = s.length();
    int t_len = t.length();
    int s_ind = 0, t_ind = 0;
    while (s_ind < s_len && t_ind < t_len) {
        if (s[s_ind] == t[t_ind]) {
            ++s_ind;
        }
        ++t_ind;
    }
    
    if (s_ind == s_len) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}
