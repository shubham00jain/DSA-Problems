//https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

bool check(vector<int>adj[], vector<int>&vis, int v, vector<int>rec){
    vis[v] = 1;
    rec[v] = 1;
    vector<int>::iterator itr;
    for(itr = adj[v].begin();itr!=adj[v].end();itr++){
        if(!vis[*itr]){
            if(check(adj,vis,*itr,rec))
                return true;
        }
        else if(vis[*itr] && rec[*itr]){
            return true;
        }
    }
    rec[v] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V,0);
    vector<int> res(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i])
            if(check(adj,vis,i,res))
                return true;
    }    
    return false;
}
