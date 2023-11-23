#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{
    std::vector<int> arr = {13, -4, 7, 1, 0, 16, 4, 3, -8, 144};
    int target_sum = 140;

    std::vector<int> res;

    std::unordered_map<int, int> hashmap;
    for (int i = 0; i < arr.size(); i++)
    {
        if (hashmap.count(arr[i]))
        {
            res.push_back(i);
            res.push_back(hashmap[arr[i]]);
        }

        int diff = target_sum - arr[i];
        hashmap[diff] = i;
    }

    if (res.size())
        std::cout << res[0] << " " << res[1] << "\n";

    return 0;
}
