#include <iostream>
#include <queue>
#include <cstring>

// bool isSubsequence(char* a, size_t size_a, char* b, size_t size_b) {
//     std::queue<char> q;
//     for (size_t i = 0; i < size_a; i++) {
//         q.push(a[i]);
//     }

//     for (size_t i = 0; i < size_b; i++) {
//         if (b[i] == q.front()) {
//             q.pop();
//         }
//         if (q.empty()) {
//             return true;
//         }
//     }

//     if (!q.empty()) {
//         return false;
//     }
//     else {
//         return true;
//     }
// }

bool isSubsequence(char* a, size_t size_a, char* b, size_t size_b) {
    size_t i = 0;
    size_t j = 0;

    while(i != size_a && j != size_b) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }

    if (i == size_a) {
        return true; 
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {

    char* a = "abc";
    char* b = "aehgakabcjbdvavd";
    // char* b = "aehgakjbdvavd";
    size_t size_a = 3;
    size_t size_b = 16;
    // size_t size_b = 13;

    if (isSubsequence(a, size_a, b, size_b)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}