#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>

#define LIST_CONSOLE_DUMP

//-------------------------------------------------------------------------------//

class Node {

    public:

        int data_ = 0;

        Node* next_ = nullptr;

        Node(int data = 0) : data_{data} {};

        ~Node() {};
};

//-------------------------------------------------------------------------------//

class LinkedList {
    
    public:

        Node* head_  = nullptr;

        Node* dummy_ = nullptr; // мнимый узел, кототрый нужен для функции удаления
                                // числа из списка, пусть он лежит в структуре списка,
                                // таким образом выделим под него память один раз при создании списка,
                                // а не каждый раз, когда будем удалять элементы

        LinkedList(int data);

        LinkedList();

        ~LinkedList();

        int InsertData(int data);

        int ListEraseData(int data);

        int ListReverse();

        bool IsLooped() const;  // new task function

        int MakeListLooped(); // makes list loop

        void ConsoleDump() const;
};

//-------------------------------------------------------------------------------//

LinkedList::LinkedList(int data)
{
    head_  = new Node(data);

    dummy_ = new Node();

    if (head_ == nullptr || dummy_ == nullptr)
    {
        std::cerr << "Failed allocation memory" << std::endl;

        return;
    }

    dummy_->next_ = head_;
}

//-------------------------------------------------------------------------------//

LinkedList::LinkedList()
{
    head_  = new Node();

    dummy_ = new Node();

    if (head_ == nullptr || dummy_ == nullptr)
    {
        std::cerr << "Failed allocation memory" << std::endl;

        return;
    }

    dummy_->next_ = head_;
}

//-------------------------------------------------------------------------------//

LinkedList::~LinkedList()
{
    Node* curr = head_;

    while (curr != nullptr)
    {
        Node* prev = curr;
     
        curr = curr->next_;

        delete prev;
    }
}

//-------------------------------------------------------------------------------//

int LinkedList::InsertData(int data)
{
    Node* curr = head_;

    Node* prev = curr;
    
    while (curr != nullptr)
    {
        prev = curr;

        curr = curr->next_;
    }

    curr = new Node(data);

    prev->next_ = curr;

    return 0;
}

//-------------------------------------------------------------------------------//

int LinkedList::ListEraseData(int data)
{
    Node* prev = dummy_;

    Node* curr = head_;

    while (curr != nullptr)
    {
        if (curr->data_ == data)
        {
            prev->next_ = curr->next_;

            delete curr;

            curr = prev->next_;
        }

        else
        {
            curr = curr->next_;

            prev = prev->next_;
        }
    }

    head_ = dummy_->next_;

    return 0;
}

//-------------------------------------------------------------------------------//

int LinkedList::ListReverse()
{
    Node* curr = head_;

    Node* prev = nullptr;

    Node* next = head_->next_;

    while (curr != nullptr)
    {
        next = curr->next_;

        curr->next_ = prev;

        prev = curr;

        curr = next;
    }

    head_ = prev;

    dummy_->next_ = head_;

    return 0;
}

//-------------------------------------------------------------------------------//

int LinkedList::MakeListLooped()
{
    Node* curr = head_;

    while (curr->next_ != nullptr)
        curr = curr->next_;

    curr->next_ = head_->next_; // making loop

    return 0;
}

//-------------------------------------------------------------------------------//

bool LinkedList::IsLooped() const
{
    if (head_->next_ == nullptr || head_->next_->next_ == nullptr)
        return false;

    Node* slow = head_->next_;

    Node* fast = head_->next_->next_;

    while (slow != fast)
    {
        if (fast->next_ == nullptr)
            return false;

        if (fast->next_->next_ == nullptr)
            return false;

        slow = slow->next_;

        fast = fast->next_->next_;
    }

    return true;
}

//-------------------------------------------------------------------------------//

void LinkedList::ConsoleDump() const
{
    #ifdef LIST_CONSOLE_DUMP

    printf("//-------------------------------------------------------//\n");

    printf("The dummy %p has data %d; the next elem is %p\n", dummy_, dummy_->data_, dummy_->next_);

    printf("The head %p has data %d; the next elem is %p\n", head_, head_->data_, head_->next_);

    Node* curr = head_->next_;
    
    while (curr != nullptr)
    {
        printf("The elem %p has data %d; the next elem is %p\n", curr, curr->data_, curr->next_);

        curr = curr->next_;
    }

    printf("//------------------------------------------------------//\n");

    #endif
}

//-------------------------------------------------------------------------------//

#endif