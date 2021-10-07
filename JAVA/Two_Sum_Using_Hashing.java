import java.util.HashSet;
import java.util.Scanner;

public class Main {
    static boolean printpairs(int arr[], int sum)
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
        int n= in.nextInt();
        int A[] = new int[n];
        for(int i=0;i<n;i++)
        {
            A[i]=in.nextInt();
        }
        int sum=in.nextInt();
        if(printpairs(A, sum))
            System.out.println("yes");
        else
            System.out.println("no");
    }
}