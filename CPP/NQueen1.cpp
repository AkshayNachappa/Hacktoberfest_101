#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            
            if(board[row][col] == 'Q') return false;
            
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '_'; 
            }
        }
 }

 int main(){

 		int n;
 		cout<<"Enter the number of Queens : ";
 		cin>>n;

 		int count = 1;
 	    vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '_'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        solve(0,board, ans, n); 

     for(vector<string> i : ans)
     {
     	cout<<"Solution : "<<count<<endl<<endl;
     	for(string s: i){
     		for(char c: s)
     			cout<<c<<" ";
     	cout<<"\n";

     	}
     	count++;
     	cout<<"\n";
     }
 }
