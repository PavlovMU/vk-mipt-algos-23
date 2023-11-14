class ListNode:
    def __init__(self, data):
        self.data = data
        self.next = None


def reverseLinkedList(head):
    prev = None
    cur = head
    while cur != None:
        temp = cur.next
        cur.next = prev
        prev = cur
        cur = temp

    head = prev
    return head


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


head = reverseLinkedList(head)
printLinkedList(head)