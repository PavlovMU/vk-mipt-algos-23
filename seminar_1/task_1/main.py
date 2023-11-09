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


def reverseLinkedList(lst: LinkedList):
    prev = None
    curr = lst.head
    while curr:
        b = curr.next
        curr.next = prev
        prev = curr
        curr = b
    lst.head = prev


if __name__ == "__main__":
    lst = LinkedList()
    for i in range(1, 11):
        lst.insert(i)

    reverseLinkedList(lst)
    lst.printLL()
