// The minimum number of edges in a graph having k connected components is n-k 
// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/description/

#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

void dfs(int v,vector<int> g[], vector<int>& vis){
        vis[v] = 1;
        for( auto i : g[v] ){
            if(!vis[i])
                dfs(i,g,vis);
        }
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c = 0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            c++;
            dfs(i,adj,vis);
        }   
    }

    if(c>k)
        cout<<-1<<endl;
    else
        cout<<m - n + k;

}
