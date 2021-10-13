import java.util.*;
public class MatAdd{  
    public static void main(String args[]){  
        int matrix[][]=new int[3][3];
        Scanner scn=new Scanner(System.in);
        System.out.println("Enter 9 numbers");
        int row,col;
        for(row=0;row<3;row++)
        {
        for(col=0;col<3;col++)
        {
        matrix[row][col]=scn.nextInt();
        }
        }
        int matrix1[][]=new int[3][3];
        Scanner scn1 = new Scanner(System.in);
        System.out.println("Enter 9 numbers for second matrix");
        int row1,col1;
        for(row1=0;row1<3;row1++)
        {
        for(col1=0;col1<3;col1++)
        {
        matrix1[row1][col1]=scn1.nextInt();
        }
        }  
        int added[][]=new int[3][3]; 
        System.out.println("The added matrix is ");    
        for(int i=0;i<3;i++)
        {    
        for(int j=0;j<3;j++)
        {    
        added[i][j]=matrix[i][j]+matrix1[i][j]; 
        System.out.print(added[i][j]+" ");    
        }    
        System.out.println();    
        }    
        }}  