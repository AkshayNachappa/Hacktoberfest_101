

import java.util.*;
import java.lang.*;
import java.io.*;


class Squares_in_a_triangle
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for(int i  =0;i<t;i++){
		    int len = scan.nextInt();
		    int ans = 0;
		    while(len>2){
		        ans = ans + (len-2)/2;
		        len = len-2;
		    }
		    System.out.println(ans);
		}
	}
}
