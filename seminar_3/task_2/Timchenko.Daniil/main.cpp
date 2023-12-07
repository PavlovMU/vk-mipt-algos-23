#include <vector>
#include <algorithm>

using namespace std;


int feedAnimals(vector<int> animals, vector<int> food) {
    int n = animals.size(), m = food.size();
    if (n == 0 || m == 0)
        return 0;

    sort(animals.begin(), animals.end());
    sort(food.begin(), food.end());

    int count = 0;
    for (int f : food) {
        if (count < m && f > animals[count])
            count++;
        if (count == n)
            break;
    }

    return count;
}
