#include <iostream>

struct node {
    int data_;
    node* next_;

    node(int data = 0, node* next = nullptr) : data_(data), next_(next) {}
};

class linked_list_int {

    public:
        node* head_;
        node* tail_;

    public:
    linked_list_int(node* head = nullptr) : head_(head) { tail_ = head; }
};

void add_node(linked_list_int &List, int data) {
    
    node* new_node = new(node);
    new_node->data_ = data;
    List.tail_->next_ = new_node;
    List.tail_ = new_node;
    new_node->next_ = nullptr;
}

void print(linked_list_int &List) {
    node* head_l = List.head_;
    while (head_l != nullptr) {
        std::cout << head_l->data_ << "  ";
        head_l = head_l->next_;
    }
    delete head_l;
}

bool check_cycle(linked_list_int &List) {
    node* slow;
    node* fast;

    slow = List.head_;
    if (slow->next_ != nullptr) 
        fast = slow->next_;
    else 
        return false;
    
    while (slow != nullptr) {
        if (slow->data_ == fast->data_) 
            return true;
        if (slow->next_ != nullptr)
            slow = slow->next_;
        else return false;
        if (fast->next_ != nullptr)
            fast = fast->next_;
        else return false;
        if (fast->next_ != nullptr)
            fast = fast->next_;
        else return false;
    }

    return true;
}

int main() {

    node* head = new(node);

    linked_list_int List(head);
    int count;
    std::cout << "Enter count of elts of list" << std::endl;
    std::cin >> count;
    int data;

    if (count > 0) {
        std::cin >> data;
        head->data_ = data;
        head->next_ = nullptr;
        linked_list_int List(head);
    }

    for (int i = 1; i < count; i++) {
        std::cin >> data;
        add_node(List, data);
    }

    print(List);
    std::cout << std::endl;

    if (check_cycle(List))
        std::cout << "CYCLE" << std::endl;
    else std::cout << "NOT CYCLE" << std::endl;

    std::cout << "checking cycle list: " << std::endl;
    node* c_head = new(node);
    c_head->data_ = 0;
    c_head->next_ = nullptr;
    linked_list_int cycle_list(c_head);
    for (int i = 1; i < 8; i++) {
        add_node(cycle_list, i);
    }
    node* temp;
    temp = cycle_list.head_->next_->next_->next_;
    cycle_list.tail_->next_ = temp;
    if (check_cycle(cycle_list))
        std::cout << "CYCLE" << std::endl;
    else std::cout << "NOT CYCLE" << std::endl;

    return 0;
}