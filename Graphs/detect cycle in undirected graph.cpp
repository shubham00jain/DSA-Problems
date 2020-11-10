//https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

bool check(vector<int>adj[], vector<int>& vis, int par, int u){
    
    vis[u] = 1;
    for(auto i : adj[u]){
        if(!vis[i]){
            bool x = check(adj,vis,u,i);
            if(x==true)
                return true;
        }
        else if(par != i || i== u) 
            return true;
    }
    return false;
}


bool isCyclic(vector<int> g[], int V)
{
       vector<int>vis(V,0);
       for(int i=0;i<V;i++){
        if( !vis[i] && check(g,vis,-1,0) )
            return 1;
       }
       return 0;
}
