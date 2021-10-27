#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[] = {-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3 };
	int n=sizeof(a)/sizeof(a[0]);
	int target=-1;
	sort(a,a+n);
	int ans=999;
	int sum;
	for(int i=0;i<n-2;i++){
		int j=i+1;
		int k=n-1;
		while(k>j){
			sum=a[i]+a[j]+a[k];
			if(abs(target-sum) < ans){
				ans=abs(target - sum);
			}
			if(target < sum) k--;
			else j++;
		}	
	}
	cout<<sum;
}
