//Разверните односвязный список.

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



func ReverseLinkedList(Node head) {
    Node prev = None
    Node next = None
    Node current = head

    while current != None {
        next = current.next
        current.next = prev
        prev = current
        current = next
    }

    return prev
}
