#include <iostream>

int copy_time(int n, int x, int y) {
	int l = 0;
	int r = (n - 1) * std::max(x, y);
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (mid / x + mid / y < n - 1) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return r + std::min(x, y);
}
int main() {
	int n, x, y;
	std::cin >> n >> x >> y;
	int res = copy_time(n, x, y);
	std::cout << res << "\n";
}
