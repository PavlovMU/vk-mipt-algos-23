#include <iostream>
#include <unordered_map>
#include <string>

std::string function_find(std::string& a, std::string& b);

std::string function_find(std::string& a, std::string& b)
{
    std::string str{};

    std::unordered_map<char, int> map_{};

    for (int i = 0; i < a.size(); i++)
    {
        map_[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (map_.count(b[i]))
            map_[b[i]]--;

        else
            str += b[i];
    }

    return str;
}

int main()
{
    std::string a = "abc";

    std::string b = "bdac";

    std::cout << function_find(a, b) << std::endl;

    return 0;
}