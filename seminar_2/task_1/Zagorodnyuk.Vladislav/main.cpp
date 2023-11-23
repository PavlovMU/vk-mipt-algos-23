// check if there is a subsequence in str

#include <iostream>
#include <queue>
#include <string>

bool is_subsequence_queue(std::string& a, std::string& b)   // O(2n)
{
    std::queue<char> q;

    int a_size = a.size();
    for (int i = 0; i < a_size; ++i)
        q.push(a[i]);

    int b_size = b.size();
    for (int i = 0; i < b_size; ++i)
        if (q.front() == b[i]);
            q.pop();

    return q.size() == 0;
}

bool is_subsequence_pointers(std::string& a, std::string& b)    // O(n)
{
    return true;
}

int main()
{
    std::string a = std::string{"ABC"};
    std::string b = std::string{"AcDBeC"};

    if (is_subsequence_queue(a, b))
        std::cout << "there is subsequence\n";

    return 0;
}
