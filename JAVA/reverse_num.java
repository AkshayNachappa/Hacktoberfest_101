import java.util.*;
public class reverse_num {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("enter the integer");
		Scanner sc=new Scanner(System.in);
		int num=sc.nextInt();
		int rev_num=0;
		while(num!=0) {
			int rem=num%10;
			rev_num=rev_num*10+rem;
			num/=10;
		}
		System.out.println(rev_num);
	}

}
