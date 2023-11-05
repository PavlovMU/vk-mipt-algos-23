#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <cassert>
#include <iostream>

void two_pointers_method(int* arr, int N, int target_sum) {
    // метод двух указателей. Подходит, если массив изначально отсортирован
    int top = 0;
    int end = N-1;

    while (arr[top] + arr[end] != target_sum) {
        if (arr[top] + arr[end] > target_sum) {
            end--;
        } else {
            top++;
        }   
    }

    assert(arr[top] + arr[end] == target_sum);
    printf("i = %d, j = %d\n", top, end);

}

void hash_map_solution(int* arr, int N, int target_sum) {
    printf("Start hash map solution\n");
    std::unordered_map<int, int> hash_table = {};
    int diff = 0;
    for (int i = 0; i < N; i++) {
        diff = target_sum - arr[i];
        if (hash_table.find(diff) == hash_table.end()) {
            hash_table[arr[i]] = i;
        } else {
            printf("i = %d, j = %d\n", i, hash_table[diff]);
            return;
        }
    }
}

int main() {
    int N = 0;
    printf("input nmber of elements in array: \n");
    scanf("%d", &N);
    int* arr = (int*) calloc(N, sizeof(int));
    for (int i = 0; i < N; ++i) {
        printf("input arr[%d]: \n", i);
        scanf("%d", &arr[i]);
    }

    int t_sum = 0;
    printf("input target sum variable: \n");
    scanf("%d", &t_sum);

    hash_map_solution(arr, N, t_sum);
    free(arr);
}