//Решение задачи удалить элемент из списка.

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
    func ctor(Node head)
    {
        this.head = head
    }
}


type ListNodeStruct {
    int data
    int next
}


//  dummy          current      val
//   ()     --->     ()    --->  (x)   --->   ()
//                    |-----------------------^

func removeElement(Node head, int val) {
    dummy = Node(None, head)
    current = head
    prev = dummy
    
    while current != None {
        if current.data == val {
            prev.next = current.next
        } else {
            prev = current
        }
        current = current.next
    }
    
    return dummy.next
}

