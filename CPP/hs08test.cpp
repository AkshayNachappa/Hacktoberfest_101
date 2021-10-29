#include <iostream>
using namespace std;

int main() {
	int m;
	float n;
	cin>>m>>n;
	if (m%5==0)
	{
	    if (m+0.5<=n)
	    {
	        printf("%.2f", n-(m+0.5));
	    }
	    else
	    {
	        printf("%.2f",n);
	    }
	}
	else 
	{
	    printf("%.2f",n);
	}
	return 0;
}
