#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{
    std::string a = "abaad";
    std::string b = "bccdaraa";
    std::string c;

    // std::cin >> a >> b;

    std::unordered_map<char, int> hashmap;

    for (int i = 0; i < a.size(); i++)
        hashmap[a[i]]++;

    for (int j = 0; j < b.size(); j++)
    {
        if (hashmap.count(b[j]))
            hashmap[b[j]]--;

        else
            c += b[j];
    }

    std::cout << c << std::endl;

    return 0;
}
