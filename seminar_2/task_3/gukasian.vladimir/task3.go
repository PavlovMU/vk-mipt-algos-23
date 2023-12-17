package main 

import "fmt" 

func binSearchSqrt(target int) int {
    var middle int

    right := target

    for left:=0; left <= right; {
        middle = (left + right) / 2

        if middle * middle > target {
            right = middle - 1
            continue
        }

        if middle * middle < target {
            left = middle + 1
            continue
        }

        return middle
    } 

    return right
}


func main() {
    fmt.Println(binSearchSqrt(17))
}
