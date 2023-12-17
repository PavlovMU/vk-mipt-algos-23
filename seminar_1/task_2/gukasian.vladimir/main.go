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

}


