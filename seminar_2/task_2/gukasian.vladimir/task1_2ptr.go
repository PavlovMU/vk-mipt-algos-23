package main 

import "fmt"

func isSubseq(str string, substr string) bool {
    var i, j int 

    for i < len(substr) && j < len(str) {
        if substr[i] == str[j] {
            i++
        }

        j++
    }

    return i == len(substr)

}

func main() {
    str    := "uabeoci"
    substr := "abc"

    fmt.Println(isSubseq(str, substr))
}






