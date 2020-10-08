//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/description/

/*
Algorithm:
1. First of all sort the adj matrix so that the shortest path which we get is lexicographically shortest as well in bfs traversal.
2. We will use a map to store the parent of every node in bfs traversal.
*/


#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

void bfs(int x, int y, map<int,int> &umap, vector<int> adj[], vector<int> vis){

    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if (u == y )
            return;

        for(int i= 0 ; i< adj[u].size(); i++){

            if(!vis[adj[u][i]]){
                umap[ adj[u][i] ] = u; 
                q.push(adj[u][i]);
                vis[adj[u][i]] = 1;
            }
        }
    }
}

int main(){
    int n,m,t,c;
    cin>>n>>m>>t>>c;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);

    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    // for(auto i:adj){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    int x,y;
    cin>>x>>y;
    map<int,int> umap;
    umap[x]=-1;
    bfs(x,y,umap,adj,vis);
    // for(auto i:umap){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    stack<int> res;
    res.push(y);
    int i = y;
    while(umap[i]!=-1){
        res.push(umap[i]);
        i = umap[i];
    }
    cout<<res.size()<<endl;
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }

}

