// @author           : Vishesh Gupta
// Space complexiety : O(1)
// Time complexiety  : O(n)
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter Number of Steps in Stairs : ";
	cin >> n;
	int x=1,y=1,ith=1,i=2;
	for(;i<=n;i++){
		// using the values of previous two steps
		ith = x + y;
		x = y;
		y = ith;
	}
	cout << "\nNumber of ways to reach Top is : " << ith;

	return 0;
} 

