class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insertAtEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return

        current_node = self.head
        while current_node.next:
            current_node = current_node.next

        current_node.next = new_node

    def printLL(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=" ")
            current_node = current_node.next
        print()

    def reverse(self):
        prev = None
        cur = self.head
        while cur is not None:
            next_ = cur.next
            cur.next = prev
            prev = cur
            cur = next_
        self.head = prev


if __name__ == "__main__":
    llist = LinkedList()
    llist.insertAtEnd(2)
    llist.insertAtEnd(4)
    llist.insertAtEnd(1)
    llist.printLL()
    print("-----reversed------------")
    llist.reverse()
    llist.printLL()
