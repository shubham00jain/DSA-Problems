//https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

#include<bits/stdc++.h>
using namespace std;

bool isInside(int x, int y, int N) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
}

int bfs(pair<int,int> k, pair<int,int> t, int n){

    vector<int> dx{ -2, -1, 1, 2, -2, -1, 1, 2 }; 
    vector<int> dy{ -1, -2, -2, -1, 1, 2, 2, 1 }; 
    
    int vis[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            vis[i][j] = 0;
        }
    }
    
    queue<pair<int,int>> q;
    q.push(k);
    vis[k.first][k.second] =1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==t.first && y == t.second){
            return vis[x][y]-1;
        }
        for(int i=0;i<dx.size();i++){
            if(isInside(x+dx[i],y+dy[i],n) && !vis[x+dx[i]][y+dy[i]]){
                vis[x+dx[i]][y+dy[i]] = vis[x][y] + 1;
                q.push(make_pair(x+dx[i],y+dy[i]));
            }
        }
    }
    return -1;
    
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int k1,k2;
	    cin>>k1>>k2;
	    pair<int,int> k(k1,k2);
	    int t1,t2;
	    cin>>t1>>t2;
	    pair<int,int> t(t1,t2);
	    cout<<bfs(k,t,n)<<endl;
	}
	return 0;
}
