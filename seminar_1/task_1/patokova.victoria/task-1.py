class ListNode:
    def __init__(self, data):
        self.data = data
        self.next = None


def delElem(head, val):
    dummy = ListNode(None)
    dummy.next = head
    prev = dummy
    cur = head

    while cur != None:
        if cur.data == val:
            prev.next = cur.next

        else:
            prev = cur

        cur = cur.next

    head = dummy.next
    del(dummy)

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

head = delElem(head, 3)
printLinkedList(head)