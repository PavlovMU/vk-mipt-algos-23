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

Node* remove_elem(struct Node* head, elem_t val)
{
    Node dummy = {0, head};
    Node* curr = head;
    Node* prev = head;

    while(curr != nullptr)
    {
        if(curr->val == val)
        {
            prev->next = curr->next;
            node_dtor(curr);
        }
        else
        {
            curr = curr->next;
        }
    }

    return dummy.next;
}

//=================================================

int main()
{
    // Node* list = list_ctor();
    // remove_elem(list, some_value);
}
