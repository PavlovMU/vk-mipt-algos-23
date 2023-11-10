typedef int elem_t;
const elem_t POISON  = (elem_t)0xDEAD;

//=================================================

enum LoopName
{
    NOT_LOOPED = 0,
    LOOPED     = 1,
};

//=================================================

struct Node
{
    elem_t val = POISON;
    Node* next = nullptr;
};

//=================================================

int is_looped(struct Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return NOT_LOOPED;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head->next;

    while(slow_ptr != fast_ptr)
    {
        if(fast_ptr == nullptr || fast_ptr->next == nullptr)
        {
            return NOT_LOOPED;
        }

        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return LOOPED;
}

//=================================================

int main()
{
    // Node* list = list_ctor();
    // if(is_looped(list))
    // {
    //     printf("The list is looped!\n");
    //     return 0;
    // }

    // printf("The list isn't looped!\n");
}
