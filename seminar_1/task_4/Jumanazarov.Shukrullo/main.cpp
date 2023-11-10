#include <iostream>

int* two_sum(int* arr, int n, int target) {
	/// arr is given sorted array
	int i = 0, j = n - 1;
	int sum = 0;
	int *res = new int[2];
	while(i != j) {
		sum = arr[i] + arr[j];
		if (sum > target) {
			j--;
		} else if (sum < target) {
			i++;
		} else {
			res[0] = arr[i];
			res[1] = arr[j];
			break;
		}
	}
	return res;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int target = 7;
	int *res = two_sum(arr, sz, target);
	for(int i = 0; i < 2; i++) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	delete[] res;
	return 0;
}
