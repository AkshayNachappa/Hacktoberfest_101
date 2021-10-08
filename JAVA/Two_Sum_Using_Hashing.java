import java.util.HashSet;
import java.util.Scanner;

public class Main {

    //method to return if a pair exists or not in an array with the given sum
    /*
    Use a hash_map to check for the current array value x(let), if there exists a 
    value target_sum-x which on adding to the former gives target_sum. 
    This can be done in constant time. 
    */
    static boolean findpairs(int arr[], int sum)
    {
        HashSet<Integer> s = new HashSet<Integer>();
        boolean b=false;
        for (int i = 0; i < arr.length; ++i)
        {
            int temp = sum - arr[i];
            if (s.contains(temp)) {
                b=true;
            }
            s.add(arr[i]);
        }
        return b;
    }
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        //input size of the array from the user
        System.out.println("Enter size of array: ");
        int n= in.nextInt();
        //Declaration of the array
        int A[] = new int[n];
        System.out.println("Enter elements of the array: ");
        //input Array elements from user
        for(int i=0;i<n;i++)
        {
            A[i]=in.nextInt();
        }
        //input sum from the user
        System.out.println("Enter the required sum to be checked: ");
        int sum=in.nextInt();
        if(findpairs(A, sum))
            System.out.println("yes");
        else
            System.out.println("no");
    }
}
