#include "list.hpp"

int main()
{
    LinkedList list = LinkedList(5);

    list.InsertData(6);

    list.InsertData(7);

    list.InsertData(8);

    std::cout << list.IsLooped() << std::endl;

    list.MakeListLooped();

    std::cout << list.IsLooped() << std::endl;

    // after this will be error, because inifinitive destruction

    return 0;
}