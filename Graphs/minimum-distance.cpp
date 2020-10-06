//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/description/
/*
Algo:
1. Use Bfs to find the level of that node and return the level.
2. We will use a container(preferable array/vector ) to store the level each node before pushing it into the queue. using level[connected node] = level[current node] + 1
*/


#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

int bfs(int v, vector<int> adj[], vector<int>& vis){
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    vector<int> level(v+1,0);
    level[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==v)
            level[u];
        for(auto i : adj[u]){
            if(!vis[i]){
                level[i] = level[u] + 1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    return level[v];

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        vector<int> vis(n+1, 0);

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout<<bfs(n,adj,vis)<<endl;
    }

}
