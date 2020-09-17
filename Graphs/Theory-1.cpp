/*
- A graph is defined as a ordered pair of Vertices and Edges.
- Study of graphs is called Graph theory.
G = (V,E).

eg.       A - B - E
          |   |   |
          D - C - F
          
- Graph can be undirected or bi-directed. In general a "graph" is undirected unless explicitly stated otherwise.

- A social network uses graph to suggest friends to a user. It simply has to suggest all the nodes which are connected to the nodes connected with the user directly. 
It is a undirected graph.

- A graph can be weighted or non-weighted i.e going to some node from start node may be costiler than the other. This can help in making a mathematical model of intercity roadmap.

- A graph can have self-loop i.e a node which is connected to itself. Both undirected and bidirected graphs can have parellel edges or multi-edges i.e. the two nodes are connected
to each other with more than 1 edge. This is useful in showing all the different flights by different companies with varying prices in a country.

- A graph having neither self-loops nor parellel edges is called a simple graph.

- max edges in a simple graph:
if |V| = n
- directed graph ->   0<=|E|<=n(n-1)
- undirected graph -> 0<=|E|<=n(n-1)/2

-dense graph - too many edges
sparse graph - less no of edges

Path - A sequence of vertices where each adjacent pair is connnected by an edge.
Simple path - A squence where no edge is repeated.
Walk - A path in which vertices can be repeated.
Trial - A sequnece where nodes can be repeated but vertices are not repeated.
A path is represented like this : <A,B,E,F> is a path from A to F.
- In graph theory there is some inconsistency in naming conventions:
A Path is sometimes refered to as a simple path and a walk is refered to as a path.

- A graph where all edges are connected to each other is called strongly connected graph.
Weakly connected - if a directed graph can be converted into a strngly connected graph by treating all the graph as undirected graph. Then its called weakly connected graph.

- Cyclic Graphs / Closed Paths - where a path can be formed in which the start and end point is same and its length is greater than 0.

A graph can be represented majorly in three ways:
1. Using Vertex List and Edge List -> Takes |E| time for scanning a node. |E| is almost equivalent to |V|^2 i.e. O(n^2). In general we want to keep our operations in O(|V|) 
and not it O(|E|).
2. Using Adjacency Matrix -> Takes too much space and time. Stores redunant 0's in every row.
3. Using Adjacency List -> Only practical way to make a graph using real world data.

/*

//NOTE: There is another way to make a graph using classes and using stl list for adj list  
//but this is the way it is made on codeforces and everywhere else.



#include<bits/stdc++.h>
using namespace std;

vector<int> Graph(int E, int V){
          vector<int> adj;
          
          for(int i = 0; i<N; i++){
                    int u,v;
                    cin>>u>>v;
                    adj[v].push_back(v);
          }
          return adj;
}

int main(){
         vector<int> adj = Graph(E,V);
}


