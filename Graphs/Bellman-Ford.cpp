/*
1. It is used to find shortest distance in a DAG when the graph contains -ve weighted edge values.
2. This is a single source algorithm.
3. It is also used to detect -ve weight cycles meaning that if the sum all the edges in a graph is -ve then we can go on relaxing the edges upto -ve infinity. 
So we return NULL in this case.

Algorithm:
1. Make a dist array and assign every value to INT_MAX. Then assign source to 0.
2. Start relaxing all the edges in the edge list. We can choose edges in any order that we want.
3. Do the step 2 |V-1| times beacuse any shortest path can have at most |V-1| edges.

https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
The input is in the form of edge list.
*/

void BellFord(vector<int>g[], int src, int n){
  vector<int> dist(n,INT_MAX);
  dist[src] = 0;
  
  for(int i=0;i<n-1;i++){
    for(int j=0;j<g.size();j++){
      if(dist[g[j][0]] + g[j][2] < dist[g[j][1]]){
        dist[g[j][1]] = dist[g[j][0]] + g[j][2];
      }
    }
  }
  
  for(int i=0;i<g.size();i++){
    int x = g[i][0];
    int y = g[i][1];
    int w = g[i][2];
    
    if(dist[x] != INT_MAX && dist[x]+w < dist[y]){
      return -1;
    }
  }
  
  return dist;
  
}
