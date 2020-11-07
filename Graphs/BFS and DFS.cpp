/*

Graph has 2 types of Traversals, namely :
1. BFS (Breadth First Search)
2. DFS (Depth First Search)

A traversal in a graph can be implemented in three ways:
1. using a vertex list and a edge list.
2. using a adjacency matrix.
3. using a adjacency list.

We will use the third way beacuse it the most efficient one.
For reasoning, watch this video again : https://www.youtube.com/watch?v=ZdY1Fp9dKzs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=40&ab_channel=mycodeschool
*/

//------------BFS--------------

//DO NOT MAKE A GRAPH USING CLASSES
//UNLESS EXPLICITLY MENTIONED


vector <int> bfs(vector<int> g[], int N) {
    
    queue<int> q;
    q.push(0);
    bool<int> visited[N+1] = {0};
    vector<int> res;
    
    
    while(!q.empty()){
        int s = q.front();
        q.pop();
        res.push_back(s);
        
        for(int i : g[s]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    
    return res;
    }
}

/*
Applications BFS:
1. Shortest path between 2 nodes
2. All nodes within one connected component
3. Find all connected components in a graph
4. Test a graph for bipartiatness 
*/



//-----------------------DFS------------------------
//-------------------using recursion----------------

void solve(int v, vector<int> adj[], vector<int>& res, vector<int>& vis){
    
    for(auto i : adj[v]){
        if(!vis[i]){
            res.push_back(i);
            vis[i] = 1;
            solve(i,adj,res,vis);
        }
    }

    return;
}

vector <int> dfs(vector<int> g[], int N)
{

    vector<int> vis(N+1, 0);
    vis[0] = 1;
    vector<int> res;
    res.push_back(0);
    solve(0,g,res,vis);
    
    return res;
}


//------------------DFS----------------------------------
//------------------using stack(iteration/ imperative code)

vector <int> dfs(vector<int> g[], int N)
{
    
    stack<int> s;
    s.push(0);
    vector<int> vis(N+1, 0);
    vis[0] = 1;
    vector<int> res;
    res.push_back(0);
    
    while(!s.empty()){
        int k = s.top();
        s.pop();
        if(!vis[k]){
            res.push_back(k);
            vis[k] = 1;
        }
            
        
        for(auto i : g[k]){
            if(!vis[i]){
               s.push(i);
            }
        }
    }
    
    return res;
}

// Time : O(|V| + ||E| )
// Space : O(|V|)
/*
Application of DFS:
1. Topological sort
2. Find connected components
3. Find articulate points
4. Find strongly connected components
5. Solve puzzles such as mazes
*/
