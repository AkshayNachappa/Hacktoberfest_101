#include<bits/stdc++.h>

using namespace std;

bool isPossible(int node,int g[][10],int colors[], int color, int n){

	for(int i=0;i<n;i++){
		if(g[node][i] == 1 && colors[i] == color){
				return false;
		}
	}

	return true;
}

bool mColoring(int g[][10], int node, int colors[], int m, int n){
	if(node == n)
		return true;

	for(int i=1;i<=m;i++){
		if(isPossible(node,g,colors,i,n)){
			colors[node] = i;
			if(mColoring(g, node+1,  colors, m, n))
			return true;
			colors[node]=0;
		}
		
	}

	return false;
}

int main(){
fstream infile; 
infile.open("Ex.txt", ios::in); 

 if (!infile) { 
 	printf("\nError to open the file\n");
 	exit (1);
 }
 int n,m;
 infile>>n; 
 int graph[10][10];
 int i,j;
 for(i=0;i<n;i++){
 	for(j=0;j<n;j++){
 		infile>>graph[i][j];
 	}
 }

 infile>>m;

 infile.close();
 int colors[n] = {0};

cout<<m<<endl;

 if(mColoring(graph,0,colors,m,n))
 	for(int i=0;i<n;i++)
 		cout<<"Vertex -> "<<i<<" Color -> "<<colors[i]<<"\n";
 else
 	cout<<"Not Possible to Color the Graph\n";

}