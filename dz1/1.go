package main

import "fmt"

func removeAndCount(arr []int, element int) (int, []int) {
    count := 0
    writeIndex := 0

    for readIndex := 0; readIndex < len(arr); readIndex++ {
        if arr[readIndex] != element {
            arr[writeIndex] = arr[readIndex]
            writeIndex++
            count++
        }
    }

    return count, arr[:count]
}

func main() {
    var n, element int
    fmt.Scan(&n)
    
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
    }
    
    fmt.Scan(&element)
    
    count, arr := removeAndCount(arr, element)
    
    fmt.Println(count)
}

