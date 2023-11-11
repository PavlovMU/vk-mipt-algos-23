#include <iostream>
#include <string>

class Stack
{
    private:
    
        size_t capacity_    = 0;

        size_t size_        = 0;

        char* data_         = nullptr;

    public:

        Stack(size_t capacity) : capacity_{capacity}
        {
            data_ = new char[capacity_];
        }

        bool IsEmpty() const
        {
            return (size_ == 0);
        }

        void Push(char data)
        {
            if (size_ == capacity_)
                return;

            data_[size_++] = data;
        }

        void Pop()
        {
            if (size_ == 0)
                return;

            size_--;
        }

        char Peek() const
        {
            return data_[size_ - 1];
        }

        void Dump() const
        {
            std::cout << "Capacity is " << capacity_ << std::endl;

            std::cout << "Size is " << size_ << std::endl;

            for (int i = 0; i < capacity_; i++)
                std::cout << data_[i] << std::endl;
        }

        ~Stack()
        {
            delete data_;
        }
};

int main()
{
    std::string word{};

    std::cin >> word;

    Stack stk{word.length()};

    for (int i = 0; i < word.length(); i++)
    {
        stk.Push(word[i]);
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == stk.Peek())
            stk.Pop();
    }

    if (stk.IsEmpty())
        std::cout << "YES" << std::endl;

    else
        std::cout << "NO" << std::endl;

    return 0;
}