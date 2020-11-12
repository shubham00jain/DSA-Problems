//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#

bool check(int x, int y, int n, int m){
    if(x < n && y < m && x>=0 && y>=0)
        return true;
    return false;
}

void dfs(vector<int>a[], vector<vector<int>>& vis, int x, int y,int n, int m){
    vector<int> dx{-1,-1,0,1,1,1,0,-1}; 
    vector<int> dy{0,-1,-1,-1,0,1,1,1};
    
    for(int i=0;i<8;i++){
        if( check(x+dx[i],y+dy[i],n,m) && a[x+dx[i]][y+dy[i]] && !vis[x+dx[i]][y+dy[i]]){
            vis[x+dx[i]][y+dy[i]] = 1;
            dfs(a,vis,x+dx[i],y+dy[i],n,m);
        }
    }
}

int findIslands(vector<int> a[], int n, int m) {

    vector<vector<int>>vis(n, vector<int>(m,0));
    int count =0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                vis[i][j] = 1;
                if(a[i][j]){
                    count++;
                    dfs(a,vis,i,j,n,m);
                }
            }
        }   
    }
    return count;
}
