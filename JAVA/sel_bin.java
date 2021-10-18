//Java implementation of Sorting and Searching
import java.util.*;
public class sel_bin
{
    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        int a[]=new int[10];
        int i,j,min,t,p,lb=0,ub=9,n,c=0;
        System.out.println("Enter 10 numbers in SDA");
        for(i=0;i<10;i++)
        {
            a[i]=in.nextInt();
        }
        for(i=0;i<9;i++)
        {
            min=i;
            for(j=i+1;j<10;j++)
            {
                if(a[j]<a[min]){
                min=j;
              }
            }
            t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
        System.out.println("Sorted array:");
        for(i=0;i<10;i++)
        {
            System.out.println(+a[i]+" ");
        }
        System.out.println("Enter search element");
        n=in.nextInt();
        while(lb<ub)
        {
            p=(lb+ub)/2;
            if(a[p]<n)
            lb=p+1;
            if (a[p]>n)
            ub=p-1;
            if(a[p]==n)
            {
                c=1;
                break;
            }
        }
        if(c==1)
        System.out.println("Element found");
        else
        System.out.println("Element not found");
    }
}