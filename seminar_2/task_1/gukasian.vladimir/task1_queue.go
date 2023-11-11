package main

import (
    "container/list"
    "fmt"
)

func isSubseq(str string, substr string) bool {
    queue := list.New()

    for _, char := range substr {
        queue.PushBack(char)
    }

    for _, char := range str {
        front := queue.Front()

        if front == nil {
            break
        }

        if front.Value == char {
            queue.Remove(front)
        }
    }

    return queue.Len() == 0
}

func main() {
    str    := "uabeoci"
    substr := "dab"

    fmt.Println(isSubseq(str, substr)) // Вернет true
}

