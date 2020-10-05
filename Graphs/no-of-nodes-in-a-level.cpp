//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/

#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

int bfs(int x, vector<int> g[], vector<int>& vis){
    queue<int> q;
    q.push(1);
    q.push(-1);
    vis[1] = 1;
    int count = 1;
    int lv = 1;
    if(x==lv)
        return count;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == -1){
            lv++;
            if(x==lv){
                return q.size();
            }
            else{
                q.push(-1);
                continue;
            }
        }

        for(auto i : g[u]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    vector<int> adj[N+1];
    vector<int> vis(N+1, 0);

    for(int i=0;i<N-1;i++){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v); 
       adj[v].push_back(u);
    }
    int x;
    cin>>x;
    cout<<bfs(x,adj,vis)<<endl;
    return 0;
}
