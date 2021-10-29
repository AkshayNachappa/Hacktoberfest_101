// Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/

// kth-largest elements in a stream
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int A, vector<int> &B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    
    for(int i=0;i<(A-1);i++){
        ans.push_back(-1);
        pq.push(B[i]);
    }
    pq.push(B[A-1]);
    ans.push_back(pq.top());
    for(int i=A;i<B.size();i++){
        if(B[i]>pq.top()){
            pq.pop();
            pq.push(B[i]);
        }
        ans.push_back(pq.top());
    }
    return ans;   
}

int main(){
    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> ans = solve(n, arr);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";

    return 0;
}