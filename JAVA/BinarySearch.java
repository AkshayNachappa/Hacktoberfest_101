////Prerequisites of Binary Search is that the array must be sorted. Here the array is sorted in ASCENDING ORDER.
import java.util.*;
class BinarySearch
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a[]={2,3,5,7,11,13,17};
        System.out.println("Enter the search value : ");
        int search= sc.nextInt();
        int f=0,b=0,e=a.length-1,m=0;
        while(b<=e)
        {
            m=(b+e)/2;
            if(search==a[m])
            {
                System.out.println("Found at index: "+ m);
                f=1;
                break;
            }
            else if(search>a[m])
                b=m+1;
            else
                e=m-1;
        }
        if(f==0)    System.out.println("Search element Not Found!");
    }
}
