#include <iostream>
#include <vector>

// Elements are in ascending order!!!
void Find_indexes(std::vector<int>& a, int el);

int main(){

    //------------------TEST_1------------------//
    std::vector<int> Test1 = {2, 4, 8, 16, 32, 64};
    int el1 = 24;  // 24 = 8 + 16

    Find_indexes(Test1, el1);

    //------------------TEST_2------------------//
    std::vector<int> Test2 = {2, 4, 8, 16, 32, 64};
    int el2 = 37;  // There is no such element

    Find_indexes(Test2, el2);

    return 0;
}

void Find_indexes(std::vector<int>& a, int el){
    
    unsigned int left = 0;
    unsigned int right = a.size() - 1;

    for (unsigned int i = 0; i < a.size(); ++i){
        if ((a[left] + a[right]) == el){
            std::cout << "The indexes are: " << left << " " << right << std::endl;

            return;
        }

        else if ((a[left] + a[right]) > el) right--;

        else left++;
    }
    std::cout << "There are no such elements\n";

}