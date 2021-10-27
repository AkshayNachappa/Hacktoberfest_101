package main

import (
        "fmt"
        "math/rand"
        "time"
        "bufio"
        "os"
        "strings"
)

const sideLength = 4
const choices = "wasd"
var empty = (sideLength * sideLength) - 1
var board [sideLength * sideLength]int

func dispBoard() {
        for i := range board {
                if i == empty {
                        fmt.Printf("   ")
                } else {
                        fmt.Printf("%02d ", board[i])
                }
                if i % sideLength == sideLength-1 {
                        fmt.Println()
                }
        }
        return
}

func move(option byte) {
        switch string(option) {
        case "a":
                if empty % sideLength == sideLength - 1 { return } // on RH wall
                board[empty], board[empty + 1] = board[empty + 1], board[empty]
                empty++
        case "d":
                if empty % sideLength == 0 { return } // on LH wall
                board[empty], board[empty - 1] = board[empty - 1], board[empty]
                empty--
        case "w":
                if empty >= sideLength * (sideLength-1) {return} // at bottom
                board[empty], board[empty + sideLength] = board[empty + sideLength], board[empty]
                empty += sideLength
        case "s":
                if empty < sideLength {return} // at top
                board[empty], board[empty - sideLength] = board[empty - sideLength], board[empty]
                empty -= sideLength
        default: // unfriendly input
        }
        return
}

func completed() bool {
        for i := range board {
                if board[i] != i + 1 {
                        return false
                }
        }
        return true
}

func init() {
        for i := range board {
                board[i] = i + 1
        }
        srcRand := rand.New(rand.NewSource(time.Now().UnixNano()))
        fmt.Println("Shuffling puzzle...")
        for iter := 0; iter < 10000000; iter++ {
                move(choices[srcRand.Intn(4)])
        }
}

func main() {
        reader := bufio.NewReader(os.Stdin)
        for {
                dispBoard()
                fmt.Print("\n\t\t\twasdq >>> ")
                text, _ := reader.ReadString('\n')
                text = strings.Replace(text, "\n", "", -1)
                if string(text[0]) == "q" { return }
                move(text[0])
                if completed() {
                        empty = -1
                        fmt.Println("\n")
                        fmt.Println("**WIN***")
                        dispBoard()
                        return
                }
        }
}
