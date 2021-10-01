/*The main objective of this program is to find number of 2x2 size squares can be fit in a right-angled isoscles triangle of a given base(in units)*/



import java.util.*;
import java.lang.*;
import java.io.*;


class Squares_in_a_triangle
{
  public static void main (String[] args) throws java.lang.Exception
  {
      Scanner scan = new Scanner(System.in);
      int base = scan.nextInt();
      System.out.println(numberOfSquares(base));
      scan.close();
  }
  public static  int numberOfSquares(int base) 
   { 
      // removing the extra part we would need always 
      base = (base - 2); 
   
      // Since each square has base of length of 2 
      base = base / 2; 
   
      return base * (base + 1)/2; 
  }
}
