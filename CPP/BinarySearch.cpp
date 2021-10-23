#include <iostream>
#include <climits>

using namespace std;



int binary_search (int arr[], int n, int key) // input array and no of elements
    {
        
        int start_point = 0;
        int end_point = n-1;
        
        while (start_point <= end_point)
        {
            
            int mid_point = (start_point + end_point) / 2;
            
            if (arr[mid_point] == key)
            {
                
                return mid_point;
                
            }
            
            else if (arr[mid_point] > key)
            
            {
                
                end_point = mid_point - 1;
                
            }
            
            else
            
            {
                
                start_point = mid_point + 1;
                
            }
            
            
            
        }
        
        return -1;     // means not present
        
    }





int main()
{
    
    
    // binary search
    // efficient way in searching key is present or not
    
    int num, key;
    
    cout << "Enter the number of elements in array: ";
    cin >> num;    // taking the no of elements in array
    
    int a[1000]; // max constraint size
    
     // taking input from user the elements
    for (int i = 0; i < num; i++)
    {
        
        cin >> a[i];
        
    }
    
    cout << "Enter the element we want to find: " ;
    cin >> key;
    
    // calling out the binary function
    
    cout << binary_search (a, num, key) <<endl;
    
    
    
    return 0;
}
