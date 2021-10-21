package test;

public class InsertionSort {

	public static void main(String[] args) {
		
		int arr[] = insertionSort(new int[] {34,6,78,34,87,98,56,98,5,8,9,1,0,-76,-54,-65,999});
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[i]+" ");
		}

	}
	public static int[] insertionSort(int [] a) {
		for(int i=1; i<a.length; i++) {
			int element = a[i];
			int j = i-1;
			while(j>=0 && a[j]>element) {
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=element;
		}
		return a;
	}

}
