/*Given a string "S" of digits. 
  (i) Find the length of it's longest sub-string having even no.of elements, such that the sum of digits in first half of the sub-string should be equal to the sum of digits in it's second half.
  
  (ii) Write a code in java with the time complexity O(n^3)
  */

/*Input : S = "23452345"
  Output = 8
  Explaination: The largest possible even substring whose sum of digits in first half is equal to it's second half with the given String "23452345" is the String itself.

  First Half : 2345
  Sum of digits in the first half : 2+3+4+5 = 14
  Second Half : 2345
  Sum of digits int the second half : 2+3+4+5 = 14
  */



  import java.util.*;
  import java.io.*;
  class EvenSubStringLength{
    public static void main(String[]args){
      Scanner scan = new Scanner(System.in);
      String S = scan.next();
      System.out.println(SubstringLength(S));
    }
    static int SubstringLength(String S){
      int n = S.length();
      int max_length = 0; // Initialize the result to zero
      
      //choose starting point of every sub-string
      for(int i = 0;i<n;i++){
         
         //choose ending point of even length sub-string
         for(int j = i+1;j<n;j+=2){

           //length of current sub-string
           int len = j-i+1;

           //calculate left and right sums for current string
           int left_sum = 0, right_sum = 0;
           for(int k = 0;k<len/2;k++){
             left_sum = left_sum + (S.charAt(i + k) - '0');
             right_sum = right_sum + (S.charAt(i + k + len/2) - '0');
           }
           if(left_sum==right_sum && max_length<len){
             max_length = len;
           }
           
         }
      }
      return max_length;
    }
  }