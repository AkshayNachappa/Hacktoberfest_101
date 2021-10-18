import java.util.*;
public class SmithNumbers
{
int sumDigit(int n)
{
int s=0;
while(n>0)
{
s=s+n%10;
n=n/10;
}
return s;
}

int sumPrimeFact(int n)
{
int i=2, sum=0;
while(n>1)
{
if(n%i==0)
{
sum=sum+sumDigit(i);
n=n/i;
}
else
{
do{
i++;
}while(!IsPrime(i));
}
}
return sum;
}
boolean IsPrime(int k)
{
boolean b=true;
int d=2;
while(d<Math.sqrt(k))
{
if(k%d==0)
{
b=false;
}
d++;
}
return b;
}
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
SmithNumbers ob=new SmithNumbers();
System.out.print("Enter a Number : ");
int n=sc.nextInt();
int a=ob.sumDigit(n);
int b=ob.sumPrimeFact(n);
System.out.println("Sum of Digit = "+a);
System.out.println("Sum of Prime Factor = "+b);
if(a==b)
System.out.print("It is a Smith Number");
else
System.out.print("It is Not a Smith Number");
}
}
