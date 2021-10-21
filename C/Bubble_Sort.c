#include<stdio.h>  
    void bubbleSort(int *A,int length){
        int i,j;
        int temp;
        for(i=0;i<length-1;i++){
             for(j=0;j<(length-1-i);j++){
                  if(A[j]>A[j+1]){
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }   
        }
    }

int main(){
    int size,i;
	printf("enter the size of array :");
	scanf("%d",&size);
	int arr[size];
	printf("enter the elements :\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}	  
	
    bubbleSort(arr,size); 
	printf("array after sorting\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    } 
    return 0;
}
