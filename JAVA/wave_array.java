import java.util.*;

public class Main {

    static void swap(int arr[],int a,int b)
    {
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

    public static void main(String[] args) {
        // write your code here
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=in.nextInt();
        }
//        Arrays.sort(a);
//        for(int i=0;i<n-1;i+=2)
//        {
//            swap(a,i,i+1);
//        }
//        System.out.println(Arrays.toString(a));
        //Method 2
        for(int i=0;i<n-1;i+=2)
        {
            if (i>0 && a[i-1] > a[i] )
                swap(a, i-1, i);

            if (i<n-1 && a[i] < a[i+1] )
                swap(a, i, i + 1);
        }
        System.out.println(Arrays.toString(a));
    }
}
