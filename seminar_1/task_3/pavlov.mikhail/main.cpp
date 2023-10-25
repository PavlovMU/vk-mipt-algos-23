//Определите является ли односвязный список закольцованным.

class Node {
    int data
    Node next
    
    func ctor(data, next){
        this.data = data
        this.next = next
    }
}

class LinkedList {
    Node head = None
    func ctor(head)
    {
        this.head = head
    }
}


type ListNodeStruct {
    int data
    int next
}



func hasCycle(Node head) {
    if head == null || head.next == null {
        return false
    }

    Node slow = head
    Node fast = head.next

    while slow != fast {
        if fast == null || fast.next == null {
            return false
        }
        slow = slow.next
        fast = fast.next.next
    }

    return true
}
