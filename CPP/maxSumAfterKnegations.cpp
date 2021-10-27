// Link : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
#include<bits/stdc++.h>
using namespace std;

int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x:A)
            pq.push(x);
        while(K--){
            int x = pq.top();
            pq.pop();
            pq.push(-x);
        }
        long ans = 0;
        while(pq.size()>0){
            ans += pq.top();
            pq.pop();
        }
        return ans;
}


int main(){
    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int k; cin>>k;
    
    cout<<largestSumAfterKNegations(arr, k);

    return 0;
}