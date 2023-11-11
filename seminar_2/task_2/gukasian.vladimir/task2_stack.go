package main

import (
    "container/list"
    "fmt"
)

func isPalindrome(str string) bool {
    stack := list.New()

    for _, char := range str {
        stack.PushBack(char)
    }

    for _, char := range str {
        back := stack.Back()
        if char != back.Value {
            return false
        }

        stack.Remove(back)
    }

    return true 
}

func main() {
    str    := "abceba"

    fmt.Println(isPalindrome(str))
}
