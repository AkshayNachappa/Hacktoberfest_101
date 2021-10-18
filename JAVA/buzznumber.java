import java.util.*;
public class buzznumber
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number");
		int n= sc.nextInt();
        int r=n%10;
        int d=n%7;
        if(r==7 || d==0)
        System.out.println(n+" is a Buzz Number");
        else
        System.out.println(n+" is not a Buzz Number");
    }
}