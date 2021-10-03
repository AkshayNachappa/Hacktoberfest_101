# Python code for implementation of MergeSort Algorithm

def mergeSort(arr):
    if len(arr) >1:
        mid = len(arr)//2   # Finding the mid of the array
        L = arr[:mid]       # Dividing the array elements 
        R = arr[mid:]       # into 2 halves
 
        mergeSort(L)        # Sorting the first half
        mergeSort(R)        # Sorting the second half
 
        i = j = k = 0
         
        # Copy data to temp arrays L[] and R[]
      
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i+= 1
            else:
                arr[k] = R[j]
                j+= 1
            k+= 1
      
      
        # Checking for the elements which were left over after first iterations
        
        while i < len(L):
            arr[k] = L[i]
            i+= 1
            k+= 1
         
        while j < len(R):
            arr[k] = R[j]
            j+= 1
            k+= 1
 

# Function to print the list
def printList(arr):
    for i in range(len(arr)):        
        print(arr[i], end =" ")
    print()
 
# driver code
if __name__ == '__main__':
    arr = [12, 11, 13, 5, 6, 7] 
    print ("Given array is", end ="\n") 
    printList(arr)
    mergeSort(arr)
    print("Sorted array is: ", end ="\n")
    printList(arr)
 
# This code is contributed by [VIBHUTI SINGH](https://github.com//VibhuRajput)
