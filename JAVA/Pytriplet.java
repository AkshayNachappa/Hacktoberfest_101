
import java.util.Scanner;

public class Pytriplet {
     public static void main(String[] args)
     {
         Scanner input = new Scanner(System.in);
         int a = input.nextInt();
         int b = input.nextInt();
         int c = input.nextInt();
         Triplet(a, b, c);
     }
     
     static void Triplet (int a, int b, int c) 
     {
       int max = Math.max(c,Math.max(a, b));
       if(max==a)
       {
        if((c*c)+(b*b) == (max*max))
        {
            System.out.println("Triplet");
        }
        else
        {
            System.out.println("not a triplet");
        }
       }
       if(max==b)
       {
        if((a*a)+(c*c) == (max*max))
        {
            System.out.println("Triplet");
        }
        else
        {
            System.out.println("not a triplet");
        }
       }
       if(max==c)
       {
        if((a*a)+(b*b) == (max*max))
        {
            System.out.println("Triplet");
        }
        else
        {
            System.out.println("not a triplet");
        }
     } 
    }
  }
