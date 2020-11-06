/*
1. Topological sort can only be done in DAGs (Directed Acyclic Graph). A tree is also a DAG. So, every tree is also in a certain topological order.
2. Just like DFS, it is not unique. Meaning that there can be 2 topo sorts of a same graph.
3. TopoSort -> If we have 2 vertices (u,v) such that u is directed towards v, then u should be printed before v.
4. It is very similar to DFS. We can even say that it a special case of DFS (don't quote it anywhere, I'm writing this myself). 
5. We can modify DFS and use a stack instead of directly printing the visited vertex. We can first visit all the vertex adjacent to the given vertex and all vertex adjacent to that
and so on... and once the recursive loop and backtracking is done, we can push the vertex in the stack.
6. Print the stack.

Applications:
1. Represent course prerequisites.
2. Detecting deadlocks.
3. Pipeline of computing jobs.
4. Checking for symbolic link loop.
5. Evaluting formulae in spreadsheet.
*/

void dfs(vector<int> adj[], int s, vector<int>& vis,vector<int>& res){
    vis[s] = 1;
    for(int i : adj[s]){
        if(!vis[i]){
            dfs(adj,i,vis,res);
        }
    }
    res.push_back(s);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    vector<int> res;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(adj,i,vis,res);    
        }
    }
    reverse(res.begin(),res.end());
    
    return res;
    
}
