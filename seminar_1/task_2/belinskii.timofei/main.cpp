#include <iostream>
#include <windows.h>

struct node {
    int data;
    node *next;

    node(int val) : data(val), next(nullptr) {};
};

struct list {
    node *head = nullptr;
    node *tail = nullptr;

    void append(int val) {
        if (head == nullptr) {
            head = new node(val);
            tail = head;
        } else {
            tail->next = new node(val);
            tail = tail->next;
        }
    }

    void print() const {
        node *cur = head;
        while (cur != nullptr) {
            std::cout << cur->data << ' ';
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        node *prev = nullptr, *cur = head;
        tail = head;
        while (cur != nullptr) {
            node *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            head = cur;
            cur = tmp;
        }
    }

    void removeElements(int val) {
        node *dummy = new node(0);
        dummy->next = head;
        head = dummy;

        node *cur = head->next;
        node *prev = dummy;

        while (cur != nullptr) {
            node *tmp;
            if (cur->data == val) {
                prev->next = cur->next;
                tmp = cur->next;
                delete cur;
            } else {
                prev = prev->next;
                tmp = cur->next;
            }
            cur = tmp;
        }
        head = dummy->next;
    }

    bool has_cycle() const {
        if (head == nullptr)
            return false;
        node *slow = head;
        node *fast = head;
        while (fast != nullptr & fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }


};

void has_sum(const int *arr, int size, int sum) {
    int tmp_sum, i = 0, j = size - 1;
    for (int k = 0; k < size; k++) {
        tmp_sum = arr[i] + arr[j];
        if (tmp_sum < sum)
            i++;
        if (tmp_sum > sum)
            j--;
        if (tmp_sum == sum) {
            std::cout << i << ' ' << j;
            return;
        }
    }
    std::cout << "Двух элементов, дающих заданную сумму нет";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Односвязный список
    list l1;
    std::cout << "Добавляем элементы\n";
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(2);
    l1.append(2);
    l1.print();
    std::cout << "Удаляем \"2\"\n";
    l1.removeElements(2);
    l1.print();
    std::cout << "Разворачиваем список\n";
    l1.reverse();
    l1.print();
    std::cout << "Сейчас список не зациклен\n";
    std::cout << l1.has_cycle() << std::endl;
    std::cout << "Зациклим список\n";
    l1.tail->next = l1.head;
    std::cout << l1.has_cycle() << std::endl;

    //Сумма двух элементов
    std::cout << "Найдем индексы двух элементов, сумма которых равна заданному числу\n";
    int sorted_arr[7] = {1, 4, 5, 7, 8, 10, 11};
    has_sum(sorted_arr, 7, 15);
    return 0;
}
