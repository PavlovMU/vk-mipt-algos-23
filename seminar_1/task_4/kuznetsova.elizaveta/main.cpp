// Задан массив целых чисел, необходимо вернуть индексы двух
// элементов, сумма которых равна заданному числу. Набор чисел 
// задан таким образом, что результат может быть только один. Нельзя 
// использовать одно и тоже число дважды.


#include <iostream>

class Arr {
    size_t size;
    size_t capacity;
    int *data;

    int findSumElem(int sum, Arr *arr) {
        int ind = 0;
        int *firstPoint = &(arr->data[0]);
        int *lastPoint = &(arr->data[arr->capacity - 1]);
        for (ind = 0; ind < arr->capacity - 1; ) {
            if (*firstPoint + *lastPoint == sum) {
                return ind;
            } else if (*firstPoint + *lastPoint < sum) {
                ind++;
                firstPoint += sizeof(int); 
            } else if (*firstPoint + *lastPoint > sum) {
                lastPoint -= sizeof(int); 
            }
        }
    }
};

int main() {

}