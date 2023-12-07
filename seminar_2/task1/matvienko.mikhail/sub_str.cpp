#include <iostream>
#include <queue>
#include <string>

bool sub_str(std::string &first, std::string &second) {
    std::queue<int> q;

    for (size_t i = 0; i < first.length(); i++) {
        q.push(first[i]);
    }

    for (size_t i = 0; i < second.length(); i++) {
        if (second[i] == q.front())
            q.pop();
        if (q.size() == 0)
            return true;
    }

    return false;
}

bool two_pts(std::string &first, std::string &second) {
    size_t f_ptr = 0;
    size_t s_ptr = 0;

    for (s_ptr = 0; s_ptr < second.length(); s_ptr++) {
        if (first[f_ptr] == second[s_ptr]) {
            f_ptr++;
        }
        if (f_ptr >= first.length())
            return true;
    }
    return false;
}

int main() 
{
    std::string first, second;

    std::cin >> first;
    std::cin >> second;

    if (sub_str(first, second)) {
        std::cout << "YES!" << std::endl;
    }

    if (two_pts(first, second)) {
        std::cout << "YES!" << std::endl;
    }

    return 0;
}