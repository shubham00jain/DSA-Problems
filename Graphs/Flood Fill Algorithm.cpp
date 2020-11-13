//https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/

#include<bits/stdc++.h>
using namespace std;


bool check(int x, int y, int n, int m){
    if(x >=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void dfs(vector<vector<int>>& mat, int n, int m, int x, int y, int k, int c){
    if( check(x+1,y,n,m) && mat[x+1][y] == c ){
        mat[x+1][y] = k;
        dfs(mat,n,m,x+1,y,k,c);
    }
    if( check(x,y-1,n,m) && mat[x][y-1] == c ){
        mat[x][y-1] = k;
        dfs(mat,n,m,x,y-1,k,c);
    }
    if( check(x,y+1,n,m) && mat[x][y+1] == c ){
        mat[x][y+1] = k;
        dfs(mat,n,m,x,y+1,k,c);
    }
    if( check(x-1,y,n,m) && mat[x-1][y] == c ){
        mat[x-1][y] = k;
        dfs(mat,n,m,x-1,y,k,c);
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--){
    	int n,m;
    	cin>>n>>m;
    	vector<vector<int>> mat(n, vector<int>(n,0));
    	for(int i=0;i<n;i++){
    	    for(int j=0;j<m;j++){
    	        cin>>mat[i][j];    
    	    }
    	}
    	int x,y,k;
    	cin>>x>>y>>k;
    	int c = mat[x][y];
    	dfs(mat,n,m,x,y,k,c);
    	for(int i=0;i<n;i++){
    	    for(int j=0;j<m;j++){
    	        cout<<mat[i][j]<<" ";
    	    }
    	}
    	cout<<endl;
	}

	return 0;
}
