package main

import "fmt"

type Node struct {
    value int
    next *Node
}

type List struct {
    head *Node
}

func (list *List) push (elem int) {
    var new_element = new(Node)
    new_element.value = elem

    if list.head == nil {
        list.head = new_element
        return
    } 

    new_element.next = list.head
    list.head = new_element
}

func (list *List) pop () int {
    if list.head == nil {
        return -1
    } 

    value := list.head.value
    list.head = list.head.next

    return value
}

func (list *List) delete (value int) {
    var dummy = new(Node) 
    dummy.next = list.head

    var cur *Node = list.head
    var prev = dummy

    for cur != nil {
        if cur.value == value {
            prev.next = cur.next
        } else {
            prev = cur
        }

        cur = cur.next
    }

    list.head = dummy.next;
}

func (list *List) reverse () {
    var prev *Node = nil;
    var cur        = list.head

    for cur != nil {
        cur.next, prev, cur = prev, cur, cur.next
    }

    list.head = prev
} 

func (list *List) is_looped () bool {
    if (list.head.next == nil) { return false }

    var slow *Node = list.head.next
    var fast *Node = list.head

    for slow != nil && fast != nil {
        if slow == fast {
            return true
        }

        slow = slow.next
        fast = fast.next
         
        if fast != nil {
            fast = fast.next
        }
    }

    return true
}

func (list *List) get_node_by_value (val int) *Node {
    var cur = list.head

    for cur != nil {
        if cur.value == val {
            return cur
        }

        cur = cur.next
    }

    return nil
}

func main() {
    var list List

    fmt.Println("first test")
    list.push(3)
    list.push(2)
    list.push(1)
    list.push(1)

    list.delete(2)

    fmt.Println(list.pop())
    fmt.Println(list.pop())
    fmt.Println(list.pop())

    fmt.Println("second test")
    list.push(3)
    list.push(2)
    list.push(1)
    list.push(1)

    list.reverse()

    fmt.Println(list.pop())
    fmt.Println(list.pop())
    fmt.Println(list.pop())
    fmt.Println(list.pop())

    fmt.Println("third test")
    list.push(3)
    list.push(2)
    list.push(1)
    list.push(1)

    var node = list.get_node_by_value(3)

    node.next = list.head

    fmt.Println(list.is_looped())
}
