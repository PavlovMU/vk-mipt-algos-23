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
    
    list.deleteElem(3)
    list.Print()

    list.deleteElem(5)
    list.Print()

    list.Append(1)
    list.deleteElem(1)
    list.Print()
    
}


