//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
// Approach is simple, do a dfs search with the start node and then check if every node is visited or not from the visited array.

#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

void dfs(vector<int> adj[], int s, vector<int>& vis){
    for(int i : adj[s]){
        if(!vis[i]){
            vis[i] = 1;
            dfs(adj,i,vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin>>s;
    vis[s] = 1;
    dfs(adj,s,vis);

    int count = 0;

    for(int i=1;i<vis.size();i++){
        if(vis[i]!=1)
            count++;
    }
    cout<<count;
}
