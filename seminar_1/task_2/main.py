class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        newNode = Node(data)
        if self.head:
            current = self.head
            while current.next:
                current = current.next
            current.next = newNode
        else:
            self.head = newNode

    def printLL(self):
        current = self.head
        while current:
            print(current.data)
            current = current.next


def delElem(head, num):
    prev = head
    while head.data != num or head.next is not None:
        if head.data == num:
            prev.next = head.next
            break
        else:
            pass
        prev = head
        head = head.next


if __name__ == "__main__":
    lst = LinkedList()
    for i in range(1, 11):
        lst.insert(i)

    delElem(lst.head, 7)
    lst.printLL()
