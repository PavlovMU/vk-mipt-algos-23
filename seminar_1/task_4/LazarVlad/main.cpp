#include <stdio.h>

//=================================================================================

typedef int elem_t;
const elem_t POISON  = (elem_t)0xDEAD;

//=================================================================================

struct Node
{
    elem_t val = POISON;
    Node* next = nullptr;
};

//=================================================================================

void find_pointers(elem_t* array, elem_t value)
{
    int left_ptr  = 0;
    int right_ptr = sizeof(array)/sizeof(array[0]); 

    elem_t sum = array[left_ptr] + array[right_ptr - 1];
    while(sum != value)
    {
        if(sum < value)
        {
            left_ptr++;
        }
        else if(sum > value)
        {
            right_ptr--;
        }

        sum = array[left_ptr] + array[right_ptr - 1];
    }

    printf("Left array pointer:  array[%d] = %d\n", left_ptr,  array[left_ptr]);
    printf("Right array pointer: array[%d] = %d\n", right_ptr, array[right_ptr]);
}

//=================================================================================

int main()
{
    // Node* list = list_ctor();
    // elem_t some_value = 12;
    // find_pointers(list, some_value);
}
