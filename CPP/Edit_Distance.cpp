#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Dynamic Programming helper function
    int helper(string s, string t, int n, int m){
        int dp[n+1][m+1];
        for(int i=0; i<m+1; i++){
            dp[0][i] = i;
        }

        for(int i=0; i<n+1; i++){
            dp[i][0] = i;
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[n][m];
    }

    int Edit_Distance(string s, string t){
        int n = s.length();
        int m = t.length();

        int ans = helper(s, t, n, m);
        return ans;


    }
};

int main() {
    string s, t;
    cout<<"Enter first String: ";
    cin>> s;
    cout<<endl;
    cout<<"Enter second String: ";
    cin>>t;
    cout<<endl;
    Solution obj;
    int op = obj.Edit_Distance(s, t);
    cout<<"Answer is: "<<op<<endl;

    return 0;
}
