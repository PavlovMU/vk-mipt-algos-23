package main 

import "fmt"

type Node struct {
  data int
  next *Node 
}

type List struct {
  head *Node
  cap  uint
  size uint
}
 
func (list *List) Append(data int) bool {
    if list.size >= list.cap {
        return false 
    }

    newNode := &Node{data: data}

    if list.head == nil {
        list.head = newNode
    } else {
        cur := list.head
        for cur.next != nil {
            cur = cur.next
        }
        cur.next = newNode
    }

    list.size++
    return true
}

func (list *List) Print() {
    cur := list.head
    for cur != nil {
        fmt.Printf("%d -> ", cur.data)
        cur = cur.next
    }
    fmt.Println("nil") // last elem
}

func (list *List) reverseList() {
    var prev *Node

    cur  := list.head

    for cur != nil {
      next    := cur.next
      cur.next = prev 
      prev     = cur 
      cur      = next 
    }
    
    list.head = prev
}

func (list *List) deleteElem(val int) {
    dummy := new(Node)
    dummy.next = list.head 

    prev := dummy 
    cur  := list.head

    for cur != nil {
        if cur.data == val {
            prev.next = cur.next 
            list.size--
        } else {
            prev = cur
        }

        cur = cur.next
    }

    list.head = dummy.next

}

func (list *List) isRing() bool {
    if list.head == nil {
        return false
    }
    
    slow := list.head 
    fast := list.head.next 

    for slow != nil && fast != nil {
        if (slow == fast) {
             return true
        }

        slow = slow.next 
        fast = fast.next 

        if (fast != nil) {
            fast = fast.next
        }
    }

    return true 
}

func (list *List) getNodeByVal(val int) *Node {
    cur := list.head

    for cur != nil {
        if cur.data == val {
          return cur
         }

        cur = cur.next
    }

    return nil 
}


func main() {
    capacity := uint(5)
    list     := &List{cap: capacity} 

    list.Append(1)
    list.Append(2)
    list.Append(3)
    list.Append(4)
    list.Append(5)

    list.Print() 

    // добавить элемент при достигнутой максимальной вместимости
    if list.Append(6) {
        fmt.Println("Элемент успешно добавлен.")
    } else {
        fmt.Println("Достигнута максимальная вместимость.")
    }
    
    // переворачиваем 
    list.reverseList()    
    list.Print()

    list.deleteElem(3)
    list.Print()

    list.deleteElem(5)
    list.Print()

    list.Append(1)
    list.deleteElem(1)
    list.Print()
    
    list.Append(1)
    list.Append(14)
    
    cur := list.getNodeByVal(14)
    cur.next = list.head 
    
    list.Print()
    
    if list.isRing() {
        fmt.Println("List is looped")
    } else {
        fmt.Println("List is straight")
    }
}


