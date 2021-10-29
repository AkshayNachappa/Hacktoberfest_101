// https://leetcode.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    long long int x;
    long long int y;
    Node(int a, int b) : x(a), y(b){}
    
};
bool operator<(const Node& p, const Node& q){
    return (p.x*p.x + p.y*p.y)>(q.x*q.x + q.y*q.y);
}
vector<vector<int> > solve(vector<vector<int> > &A, int B) {
    priority_queue<Node> pq;
    vector<vector<int>> ans;
    for(auto arr : A){
        // Node nn = new Node(arr[0], arr[1]);
        pq.push(Node(arr[0], arr[1]));
    }
    while(B-- && !pq.empty()){
        vector<int> temp(2);
        temp[0] = pq.top().x;
        temp[1] = pq.top().y;
        ans.push_back(temp);
        pq.pop();
    }
    return ans;
}

int main(){
    int n;cin>>n;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            cin>>arr[i][j];
    int k; cin>>k;

    vector<vector<int>> ans = solve(arr, k);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        } 
        cout<<endl;
    }

    return 0;
}