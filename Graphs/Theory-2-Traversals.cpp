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
//UNLESS EXPLICITLY SAid


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








