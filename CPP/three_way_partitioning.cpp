// Three way partitioning

#include <bits/stdc++.h>
using namespace std;

void inti_code() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

void threeWayPartition(vector<int> &arr, int a, int b)
{
	int low = 0, mid = 0, high = arr.size() - 1;

	while (mid <= high)
	{
		if (arr[mid] < a) {
			swap(arr[mid], arr[low]);
			low++, mid++;
		}
		else if (arr[mid] > b) {
			swap(arr[mid], arr[high]);
			high--;
		} else {
			mid++;
		}
	}
}

int main() {
	inti_code();

	int n; cin >> n;

	int a, b;

	cin >> a >> b;

	vector<int> vec;
	for (int i = 1; i <= n; ++i) {
		int t; cin >> t;
		vec.push_back(t);
	}

	threeWayPartition(vec, a, b);

	for (int i = 0; i < n; ++i)
		cout << vec[i] << " ";

	return 0;
}
