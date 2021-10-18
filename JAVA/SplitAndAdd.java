/*SPLIT AN ARRAY INTO TWO PARTS AND ADD FIRST PART OF THE ARRAY AT THE END*/

/* Given an array 'A' which consists of 'N' elements. Input any position 'P' and split the array into two parts from that position then add the first part of the array to the end. */

/* Input :
      N = 6
      A[] = {12, 45, 56, 1, 34, 67}
      P = 2
   Output :
      A[] = {56, 1, 34, 67, 12, 45}
   Here we splitted from position 2 and added first part {12, 45} to the end*/

import java.util.*;
class SplitAndAdd{
  public static void main(String[]args){
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();  
    int A[] = new int[n];    
    int P = scan.nextInt(); //position.
    for(int i = 0;i<n;i++){
      A[i] = scan.nextInt();
    }
    SplitAndAdd(A,n,P);
    for(int j = 0;j<A.length;++j){
      System.out.print(A[j]+" ");
    }
    scan.close();
  }
  public static void SplitAndAdd(int arr[], int size, int pos){
    for(int i = 0;i < pos;i++){
      //Rotate array by 1
      int x = arr[0];
            for (int j = 0; j < size - 1; ++j){
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = x;
    }
  }
}