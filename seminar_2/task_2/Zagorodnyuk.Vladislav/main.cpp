// check if word is a polynom

#include <iostream>
#include <stack>
#include <string>

bool is_polyndrom_stack(std::string& str)   // O(2n)
{
    std::stack<char> stack;

    int str_size = str.size();
    for (int i = 0; i < str_size; ++i)
        stack.push(str[i]);

    for (int i = 0; i < str_size; ++i)
    {
        if (str[i] != stack.top())
            return false;

        stack.pop();
    }

    return true;
}

bool is_polyndrom_pointers(std::string& str)    // O(n)
{
    int l = 0;
    int r = str.size()-1;

    while (l <= r)
        if (str[l++] != str[r--])
            return false;

    return true;
}

int main()
{
    std::string str = std::string{"sabobas"};

    if (is_polyndrom_stack(str))
        std::cout << "polyndrom\n";

    if (is_polyndrom_pointers(str))
        std::cout << "polyndrom\n";

    return 0;
}
