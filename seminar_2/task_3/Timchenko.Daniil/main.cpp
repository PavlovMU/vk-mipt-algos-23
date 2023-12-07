using namespace std;

int binarySearchSqrt(int target) {
    int l = 0, r = target;

    while (l <= r) {
        int middle = (l+r) / 2;

        if (middle * middle < target) {
            l = middle + 1;
            continue;
        }

        if (middle * middle > target) {
            r = middle - 1;
            continue;
        }

        return middle;
    }

    return r;
}