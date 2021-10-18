import java.util.*;
class Special
{
	static int fact(int n)
	{
		int f=1;
		while(n!=0)
			{
			f=f*n;
			n--;
		}
		return f;
	}
	static boolean check(int n)
	{
		int sum = 0;
		int t=n;
		while (t!= 0) 
		{
			sum += fact(t%10);
			t=t/10;
		}
		return (sum==n);
	}
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		while(T-->0)
		{
			int n =sc.nextInt();
			if (check(n))
			System.out.println("Special Number");
			else
			System.out.println("Not a Special Number");
		}
	}
}
