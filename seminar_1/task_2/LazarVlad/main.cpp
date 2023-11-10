typedef int elem_t;
const elem_t POISON  = (elem_t)0xDEAD;

//=================================================

struct Node
{
    elem_t val = POISON;
    Node* next = nullptr;
};

//=================================================

void node_dtor(struct Node* node)
{
    node->val  = POISON;
    node->next = nullptr;
}

//=================================================

Node* reverse_list(struct Node* head)
{
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while(curr != nullptr)
    {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }

    return prev;
}

//=================================================

int main()
{
    // Node* list = list_ctor();
    // reverse_list(list);
}
