import java.util.*;
public class firstrepeatingarrayelement
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
// 		System.out.println("Enter the number of elements of your array");
// 		int m= sc.nextInt();
// 		int arr[] = new int[m];
// 		System.out.println("Enter the elements of your array");
// 		for(int i=0;i<arr.length;i++)
// 		{
// 			arr[i]=sc.nextInt();
// 		}
// Added the following code to make it user friendly		
		System.out.println("Enter the elements of your array");
        	String num = sc.nextLine();
        	String[] arr = num.split("\\s+");
		int n=0;
		for(int i=0;i<arr.length;i++)
		{
			for(int j=i;j<arr.length;j++)
			{
			    if(arr[i].equals(arr[j]))
				n++;
			}
			if(n>1)
			{
			System.out.println("The first repeating element is "+arr[i]);
			System.out.println(arr[i]+" occurs "+n+" times in the entered array");
			break;
			}
			n=0;
		}
	}
}
