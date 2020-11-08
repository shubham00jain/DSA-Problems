/*
1. Dijkstra Algorithm is used to find shortest path from a single source in a weighted graph. 
2. It fails if any weight is negative so it should only be used with +ve weights.

Algorithm:
1. Create a min heap priority_queue of pair<int,int>. 
The elements should always be in the form of (weights,vertex) beacuse pq will arrange them according to the first value in the pair.
2. Make a dist vector which will store the distance of every vertex to the source vertex. Intialise every vertex to INT_MAX or INF.
3. Push the source vertex (0,0) in pq  and make its dist[src] = 0.
4. Loop until pq is not empty and relax every min vertex if it satisfies the conditions [see code].


https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/?ref=lbp
*/

int dijkstra(vector<int> adj, int src, int des, int n){
priority_queue<pair<int,int>, vector<pair<int,int>>, greater< pair<int,int> > > pq;
vector<int> dist(n,INT_MAX);
dist[src] = 0;
pq.push(make_pair(0,src));

while(!pq.empty()){
  int u = pq.top().second;
  pq.pop();
  for(auto i : adj[u]){
    int v = i.first;
    int w = i.second;
    if(dist[v] >  dist[u] + w){
      dist[v] = dist[u]+w;
      pq.push_back(make_pair(dist[v], v));
    }
  }
}
return dist[des];

}

int main(){
int n;
cin>>n;
vector<pair<int,int>> adj[];

for(int i=0;i<n;i++){
int u,v,w;
cin>>u>>v>>w;
adj[u].push_back(make_pair(v,w));
}

int src,des;
cin>>src>>des;
cout<<dijkstra(adj,src,des, n); 
}
