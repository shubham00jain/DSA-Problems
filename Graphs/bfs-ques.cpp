// Read the problem statement here: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/submissions/
//

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> g[], int N, unordered_map<int,int> umap){

    queue<int> q;
    q.push(1);
    q.push(-1);
    vector<int> vis(N+1,0);
    int ans = INT_MAX;
    int find = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == -1){
            if(find==1)
                break;

            if(!q.empty())
                q.push(-1);
            continue;
        }

        if(!vis[curr]){
            vis[curr] = 1;
            if(umap.find(curr)!=umap.end()){
                if(curr < ans){
                    ans = curr;
                    find =1;                    
                }
            }
        }

        for(auto i : g[curr]){
            if(!vis[i]){
                q.push(i);              
            }
        }
    }
        
    return ans;

}

int main(){

    int N;
    cin>>N;
    vector<int> adj[N+1];

    for(int i=0 ; i<N-1 ; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // for(int i=0;i<N;i++){
    //     cout<<i <<": ";
    //     for(auto x : adj[i])
    //         cout<<x << " ";
    
    //     cout<<endl;
    // }
    
    

    unordered_map<int, int> umap;
    int k;
    cin>>k;

    for(int i =0; i<k;i++){
        int t;
        cin>>t;
        umap[t] = 1;
    }
    cout<<solve(adj, N, umap);
}
