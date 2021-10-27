package main

import (
        "fmt"
        "os"
        "sync"
)

const PRINT_ALL = false
const Q_SIZE = 15000
const THREADS = 32

func display(sudoku []int) {
        for ind, num := range sudoku {
                fmt.Print(num, " ")
                if ind%3 == 2 {
                        fmt.Print(" ")
                }
                if ind%9 == 8 {
                        fmt.Println()
                }
                if ind%27 == 26 {
                        fmt.Println()
                }
        }
        if PRINT_ALL {
                fmt.Println("-------------------------")
                fmt.Println()
        }
}

func brancher(jobs chan<- [82]int, sudoku []int, output *sync.Mutex) {
        pos := sudoku[81]
        var c int
        var bad uint16 = 0
        startrow := (pos / 9) * 9 // checks rows
        for c = startrow; c < startrow+9; c++ {
                bad |= 1 << sudoku[c]
        }

        startcol := pos % 9 // checks columns
        for c = startcol; c < startcol+81; c += 9 {
                bad |= 1 << sudoku[c]
        }

        sboxc := (startcol / 3) * 3 // checks boxes
        sboxr := (startrow / 27) * 27
        for offset := 0; offset < 27; offset += 9 {
                grp := sboxc + sboxr + offset
                for c = grp; c < grp+3; c++ {
                        bad |= 1 << sudoku[c]
                }
        }

        next := 81
        for c := pos + 1; c < 81; c++ { // find the next blank
                if sudoku[c] == 0 {
                        next = c
                        break
                }
        }
        sudoku[81] = next

        for num := 1; num < 10; num++ {
                if (bad>>num)&1 == 0 { // if the number can go here
                        sudoku[pos] = num
                        if next == 81 {
                                output.Lock()
                                display(sudoku[:81])
                                if PRINT_ALL {
                                        output.Unlock()
                                } else {
                                        os.Exit(0)
                                }
                        } else {
                                if len(jobs) < Q_SIZE {
                                        var new [82]int
                                        copy(new[:], sudoku)
                                        jobs <- new
                                } else {
                                        brancher(jobs, sudoku, output)
                                }
                        }
                }
        }
        sudoku[pos] = 0
        sudoku[81] = pos
}

func worker(jobs chan [82]int, wg *sync.WaitGroup, output *sync.Mutex) {
        defer wg.Done()
        for sudoku := range jobs {
                brancher(jobs, sudoku[:], output)
        }
}

func main() {
        var wg sync.WaitGroup
        var output sync.Mutex
        jobs := make(chan [82]int, Q_SIZE)
        sudoku := [82]int{
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 3, 0, 8, 5,
                0, 0, 1, 0, 2, 0, 0, 0, 0,
                0, 0, 0, 5, 0, 7, 0, 0, 0,
                0, 0, 4, 0, 0, 0, 1, 0, 0,
                0, 9, 0, 0, 0, 0, 0, 0, 0,
                5, 0, 0, 0, 0, 0, 0, 7, 3,
                0, 0, 2, 0, 1, 0, 0, 0, 0,
                0, 0, 0, 0, 4, 0, 0, 0, 9,
        }
        //var sudoku [82]int
        sudoku[81] = 0
        jobs <- sudoku
        for i := 0; i < THREADS; i++ {
                wg.Add(1)
                go worker(jobs, &wg, &output)
        }
        wg.Wait()
}
