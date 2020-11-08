/*
1. This algorithm is based on the fact that every DAG has atleast one vertex with indegree equal to 0.
2. This algorithm is useful in checking if the given graph is a DAG or not.

Algorithm:
1. Make a array which contains indegree of all vertex and intialize it to 0 and make count = 0.
2. Make a queue and push all the vertex with indegree equal to zero inside it.
3. Loop until queue is empty and pop each vertex u from the queue and loop through adj[u] and update ingedegree of all adjacent vertices to u.
4. Push u in ans array. Increase count every time this happens.
5. If count != number of vertices, there is cycle in the graph and it not a DAG.

https://www.youtube.com/watch?v=cIBFEhD77b4&ab_channel=WilliamFiset
https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
*/

void khan(vector<int> adj[], int v){
  queue<int> q;
  vector<int> indegree(v,0);
  vector<int> toposort;
  int count =0;
  
  for(auto i : adj){
    for(auto j : i){
      indegree[j]++;
    }
  }
  
  for(int i = 0; i < indegree.size();i++){
    if(indegree[i]==0)
      q.push(i);
  }
  
  while(!q.empty()){
    int u = q.front();
    q.pop();
    toposort.push_back(u);
    for(auto i : adj[u]){
      indegree[i]--;
      if(indegree[i]<=0)
        q.push(i);
    }  
    count++;
  }
  
  if(count == n)
    return toposort;
  else 
    return -1;
}
