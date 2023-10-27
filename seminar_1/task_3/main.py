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


def isLooped(head):
    slow = head
    fast = head
    flag = 0
    while fast and slow and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            flag = 1
            break
    return flag


if __name__ == "__main__":
    lst = LinkedList()
    lst.insert(1)
    curr = lst.head
    cycle = None
    for i in range(2, 11):
        lst.insert(i)
        if i == 3:
            cycle = curr
        curr = curr.next
    curr.next = cycle

    print(isLooped(lst.head))
