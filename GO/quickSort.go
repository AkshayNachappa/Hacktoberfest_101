package main

import "fmt"

func main() {
	// Example unsorted array
	a := []int{15, 6, 2, 3, 12, 4, 5, 6, 9, 10}
	// Print unsorted array
	fmt.Println(a)
	// Sort the array
	a = quickSort(a, 0, len(a)-1)
	// Print sorted array
	fmt.Println(a)
}

// partition divides given array into two partitions
func partition(arr []int, lo int, hi int) ([]int, int) {
	// Choose pivot to be the last element
	pivot := arr[hi]
	// Pivot index
	i := lo
	// Loop through array
	for j := lo; j < hi; j++ {
		// If the current element is less than or equal to the pivot
		if arr[j] < pivot {
			// Swap the current element with the element at the pivot
			arr[i], arr[j] = arr[j], arr[i]
			// Move the pivot index forward
			i++
		}
	}
	// Swap pivot element with element on end pointer
	arr[i], arr[hi] = pivot, arr[i]
	// Return the pivot index
	return arr, i
}

// quickSort takes an array to sort, its starting and ending index
func quickSort(arr []int, lo int, hi int) []int {
	// If indices are in correct order
	if lo >= 0 && hi >= 0 && lo < hi {
		// Partition array and get pivot index
		arr, p := partition(arr, lo, hi)

		// Sort the two partitions
		arr = quickSort(arr, lo, p-1) // Left side of pivot
		arr = quickSort(arr, p+1, hi) // Right side of pivot
	}
	return arr
}
