class ListNode:
    def __init__(self, data):
        self.data = data
        self.next = None


def hasCycle(head):
    if head == None or head.next == None:
        return False
    slow = head
    fast = head.next
    while fast != slow:
        if fast.next != None and fast.next.next != None:
            slow = slow.next
            fast = fast.next.next
        else:
            return False
    return True


def printLinkedList(head):
    cur = head
    while cur != None:
        print(cur.data)
        cur = cur.next

        
e1 = ListNode(1)
e2 = ListNode(2)
e3 = ListNode(3)
e4 = ListNode(4)
e5 = ListNode(3)

e1.next = e2
e2.next = e3
e3.next = e4
e4.next = e5

head = e1

print(hasCycle(head))

e5.next = e2
print(hasCycle(head))