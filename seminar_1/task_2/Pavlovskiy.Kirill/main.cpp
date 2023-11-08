#include "list.hpp"

int main()
{
    LinkedList list = LinkedList(5);

    list.InsertData(3);

    list.InsertData(10);

    list.InsertData(6);

    list.ConsoleDump();

    list.ListReverse();

    list.ConsoleDump();

    return 0;
}