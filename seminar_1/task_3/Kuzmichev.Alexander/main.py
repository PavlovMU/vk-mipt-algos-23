class Node:
    def __init__(self, data=None, link=None):
        self.data = data
        self.next = link


class LinkedList:
    def __init__(self):
        self.head = None

    def print_list(self):
        if self.head is None:
            print('Empty')
            return

        current = self.head
        while current:
            print(current.data, end=' ')
            current = current.next
        print()

    def add_at_begining(self, data):
        if self.head is None:
            node = Node(data)
            self.head = node
            return

        node = Node(data, self.head)
        self.head = node

    def add_at_end(self, data):
        if self.head is None:
            node = Node(data)
            self.head = node
            return

        cur = self.head
        while cur.next:
            cur = cur.next
        node = Node(data)
        cur.next = node

    def remove_data(self, data):
        current = self.head
        if current.data == data:
            self.head = current.next
            return

        prev = current
        current = current.next
        while current:
            if current.data == data:
                prev.next = current.next
                return
            prev = current
            current = current.next

    def reverse(self):
        if self.head is None:
            return
        if self.head.next is None:
            return

        prev = self.head
        cur = prev.next
        prev.next = None
        next_cur = cur.next
        while cur:
            cur.next = prev
            if next_cur is None:
                break
            prev = cur
            cur = next_cur
            next_cur = next_cur.next
        self.head = cur

    def circle(self):
        if self.head is None:
            return False
        if self.head.next is None:
            return False

        slow = self.head
        fast = self.head.next
        while fast != slow:
            if fast.next is None or fast is None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True

