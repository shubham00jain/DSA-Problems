//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

bool valid(int x, int y, int n){
    if(x >=0 && x < n && y >=0 && y <n)
        return true;
    return false;
}

void dfs(int m[MAX][MAX], int n, vector<vector<int>>&vis, int x, int y,
            string path, vector<string>& res ){
                
    vis[x][y] = 1;
    
    if( x==n-1 && y==n-1 ){
        res.push_back(path);
        path.pop_back();
    }
    
    if( valid(x+1,y,n) && m[x+1][y] && !vis[x+1][y] ){
        dfs(m,n,vis,x+1,y,path+"D" ,res );
    }
    if( valid(x,y-1,n) && m[x][y-1] && !vis[x][y-1] ){
        dfs(m,n,vis,x,y-1,path+"L",res );
    }
    if( valid(x,y+1,n) && m[x][y+1] && !vis[x][y+1] ){
        dfs(m,n,vis,x,y+1,path+"R",res );
    }
    if( valid(x-1,y,n) && m[x-1][y] && !vis[x-1][y] ){
        dfs(m,n,vis,x-1,y,path+"U",res );
    }
    
    vis[x][y] = false;
}


vector<string> printPath(int m[MAX][MAX], int n) {
    vector<vector<int>> vis(n, vector<int>(n,0));
    string s = "";
    vector<string>res;
    
    if(m[0][0]==0){
        res.push_back(to_string(-1));
        return res;
    }
        
    
    dfs(m,n,vis,0,0,s,res);
    if(res.size())
        return res;
    
    else{
        vector<string> a;
        a.push_back("-1");
        return a;    
    }
    
}
