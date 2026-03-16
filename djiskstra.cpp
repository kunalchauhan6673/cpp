#include <bits/stdc++.h>
using namespace std;

#define MAX 100

/*** making an adjacency list i.e..
graph[] -> pair(neighbouring vertex, weight of the edge)
eg: graph[1] -> (2,10) (3,5) ***/

vector<pair<int,int>> graph[MAX];

void dijkstra(int n, int src){

/*** Priority queue used as a Min Heap.
Stores (distance, vertex) so that the vertex with
the smallest distance is always extracted first. ***/
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

/*** visited keeps track of vertices already processed(true)
and not processed(false) in the shortest path tree ***/
bool visited[MAX]={false};

/*** dist[] stores the shortest distance from the source
to every vertex.
Initially all distances are INT_MAX (infinity).

Then we start from the source vertex and push
(distance=0, source) into the queue ***/
int dist[MAX];
for(int i=1;i<=n;i++)
    dist[i]=INT_MAX;
dist[src]=0;
pq.push({0,src});

while(!pq.empty()){

    /*** .top fetches the whole pair,
    .top().second fetches vertex and stores in u.
    Then the pair is removed from the queue ***/
    int u=pq.top().second;
    pq.pop();

    if(visited[u]) continue; // if vertex already processed, ignore it

    visited[u]=true; // mark vertex as processed

    /*** We check for every adjacent vertex(v,w) of u here
    -> if distance through u is smaller than current dist[v],
       then update dist[v]
    -> then insert (dist[v], v) in priority queue
    -> repeat for all neighbouring vertices of u ***/
    for(auto edge:graph[u]){
        int v=edge.first;
        int weight=edge.second;

        if(dist[u] + weight < dist[v]){
            dist[v] = dist[u] + weight;
            pq.push({dist[v], v});
        }
    }
}

/*** finally print shortest distance from source
to every vertex ***/
cout<<"Shortest distances from source "<<src<<":\n";

for(int i=1;i<=n;i++)
    cout<<"Vertex "<<i<<" = "<<dist[i]<<endl;
}

int main(){

    int n,e;
    cout<<"Enter vertices and edges: ";
    cin>>n>>e;

    cout<<"Enter edges (u v w):\n";

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int src;
    cout<<"Enter source vertex: ";
    cin>>src;

    dijkstra(n,src);
}
