#include <iostream>
#include <string>

// очередь на двусвязном списке

class Node
{
    public:

        char data_  = ' ';

        Node* next_ = nullptr;

        Node* prev_ = nullptr;

        Node() {}

        Node(const char data) : data_{data} {}
};

class Queue
{
    public:

        size_t size_        = 0;

        size_t capacity_    = 0;

        Node* head_         = nullptr; // начало очереди

        Node* tail_         = nullptr; // конец  очереди

        Queue(const size_t capacity) : capacity_{capacity} 
        {
            head_ = new Node();

            tail_ = new Node();

            head_->next_ = tail_;

            tail_->prev_ = head_;
        }

        ~Queue()
        {
            Node* curr = head_;

            while (curr != tail_)
            {
                Node* prev = curr;

                curr = curr->next_;

                delete prev;
            }

            delete tail_;

            // std::cout << "destructor" << std::endl;
        }

        void Push(char data)
        {
            if (size_ >= capacity_)
                return;

            Node* new_node = new Node(data);

            new_node->next_ = head_->next_;

            new_node->prev_ = head_;

            new_node->next_->prev_ = new_node;

            head_->next_ = new_node;

            size_++;
        }

        void Pop()
        {
            if (size_ == 0)
                return;

            Node* erase_node = tail_->prev_;

            erase_node->prev_->next_ = tail_;

            tail_->prev_ = erase_node->prev_;

            delete erase_node;

            size_--;
        }

        char Peek() const // возвращает значение первого элемента очереди
        {
            if (size_ == 0)
                return ' ';

            return tail_->prev_->data_;
        }

        void Dump() const
        {
            std::cout << "head: " << head_ << " next: " << head_->next_ << " prev: " << head_->prev_ << std::endl;

            Node* curr = head_->next_;

            while (curr != tail_)
            {
                std::cout << "elem: " << curr << " data: " << curr->data_ << " next: " << curr->next_ << " prev: " << curr->prev_ << std::endl;
                curr = curr->next_;
            }

            std::cout << "tail: " << tail_ << " next: " << tail_->next_ << " prev: " << tail_->prev_ << std::endl;

        }
};

int main()
{
    std::string str1{};

    std::cin >> str1;

    std::string str2{};

    std::cin >> str2;

    int size1 = str1.length();

    Queue queue(size1);
    
    for (int i = 0; i < size1; i++)
    {
        queue.Push(str1[i]);
    }

    int size2 = str2.length();

    for (int i = 0; i < size2; i++)
    {
        if (queue.Peek() == str2[i])
            queue.Pop();
    }

    if (queue.size_ == 0)
        std::cout << "YES" << std::endl;

    else
        std::cout << "NO" << std::endl;

    return 0;
}