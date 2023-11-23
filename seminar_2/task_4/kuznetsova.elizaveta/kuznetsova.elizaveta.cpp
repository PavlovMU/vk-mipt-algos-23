#include <iostream>
#include <algorithm>

int copyTime(int numberCopy, int firstPrintner, int secondPrinter) {
    int left = 0; 
    int right = (numberCopy -1) * std::max(firstPrintner, secondPrinter);
    int middle = 0;
    
    while (left + 1 < right) {
        middle = (right + left) / 2;
        if (middle/firstPrintner + middle/secondPrinter < numberCopy - 1) {
            left = middle;
        } else {
            right = middle;
        }
    }
    
    return right + std::min(firstPrintner, secondPrinter);
}



int main() {
    size_t numberCopy, firstRinter, secondPrinter;
    std::cin >> numberCopy >> firstRinter >> secondPrinter;
    std::cout << copyTime(numberCopy, firstRinter, secondPrinter) << std::endl;
}