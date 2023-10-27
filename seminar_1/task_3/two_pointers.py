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

    def remove(self, val):
        dummy = Node(-1)
        dummy.next = self.head
        prev = dummy
        cur = self.head
        while cur is not None:
            # print(cur.data, prev.data)
            if cur.data == val:
                next_ = cur.next
                prev.next = next_
                # print("удалил")
            else:
                prev = prev.next
            cur = cur.next
        self.head = dummy.next

    def is_circle(self):
        slow = self.head
        if slow.next is not None:
            fast = slow.next
        else:
            return False
        if fast.next is None:
            return False

        while slow != fast:
            if slow.next is not None:
                slow = slow.next
            else:
                return False

            for i in range(2):
                if fast.next is not None:
                    fast = fast.next
                else:
                    return False
        return True

    def get_tail(self):
        current_node = self.head
        prev = None
        prevprev = None
        i = 0
        while current_node:
            if i > 1:
                prevprev = prev
            prev = current_node
            current_node = current_node.next
            i += 1
        return prev, prevprev


if __name__ == "__main__":
    llist = LinkedList()
    llist.insertAtEnd(4)
    llist.insertAtEnd(2)
    llist.insertAtEnd(1)
    print(llist.is_circle())
    # False (is not circle)

    tail, prev = llist.get_tail()
    tail.next = prev
    prev.next = tail
    print(llist.is_circle())
    # True (is circle)
