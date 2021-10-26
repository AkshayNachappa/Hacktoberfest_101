// Sort an array of 0s , 1s and 2s without using sorting algo

#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	int temp;
	for (i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int beg = 0;
	int end = n-1;
	i=0;
	while (i<=end)
	{
		if (arr[i]==0)
		{
			temp = arr[i];
			arr[i] = arr[beg];
			arr[beg] = temp;
			beg++;
			i++;
		}
		else if (arr[i]==2)
		{
			temp = arr[i];
			arr[i] = arr[end];
			arr[end] = temp;
			end--;
		}
		else
		i++;
	}
	for (i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
