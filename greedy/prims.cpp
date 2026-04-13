#include <bits/stdc++.h>
using namespace std;

#define MAX 100

/*** making an adjacency list i.e..
graph[] -> pair(neighbouring vertex, weight of the edge)
eg: graph[1] ->(2,10) (3,5) ***/

vector<pair<int,int>> graph[MAX];

void prim(int n){

/*** Priority queue used as a Min Heap.
Stores (weight, vertex) so that the edge with
the smallest weight is always extracted first. ***/
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

// inMst keeps track of verteces already included(true) and not included(false) in the mst
    bool inMST[MAX]={false};

/*** key is the minimum weight edge to connect vertex to the mst
and it is initially INT_Max or infinity.
Then, we start mst from vertex 1
and push (weight=0, vertex=1) in queue ***/
    int key[MAX];
    int parent[MAX];
    for(int i=1;i<=n;i++)
        key[i]=INT_MAX;
    key[1]=0;
    pq.push({0,1});

    int cost=0; // stores total weight of the mst

    while(!pq.empty()){

        /*** .top fetches the whole pair,
        .top().second fetches vertex and stores in u,
        .top().first fetches weight and stores in w.
        And then the whole pair is popped from the queue***/
        int u=pq.top().second;
        int w=pq.top().first;
        pq.pop();

        if(inMST[u]) continue; // if vertex in mst, ignore it

        inMST[u]=true;// else mark u as true and add weight to cost
        cost+=w;

            if(parent[u]!=0){
          char ch1 = 'A'+u-1;
          char ch2 = 'A'+parent[u]-1;
          cout<<ch1<<" - "<<ch2<<" :"<<key[u]<<endl;

    }
        /*** We check for every adjacent vertex(v,w) of u here
        -> if v neighbour vertex of u is not in mst and its weight is less than key[v], then update key[v]
        ->then insert (w,v) in priority queue
        -> repeat for all neighbouring vertex of u***/
        for(auto edge:graph[u]){
            int v=edge.first;
            int weight=edge.second;

            if(!inMST[v] && weight < key[v]){
                key[v]=weight;
                parent[v]=u;
                pq.push({weight,v});
            }
        }
    }

    cout<<"Minimum Cost = "<<cost<<endl;
}

int main(){

    int n,e;
    cout<<"Enter vertices and edges: ";
    cin>>n>>e;

    cout<<"Enter edges (u v w):\n";

    for(int i=0;i<e;i++){
        char ch1,ch2;
        int w;
        cin>>ch1>>ch2>>w;
        int u=ch1-'A'+1;
        int v=ch2-'A'+1;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});

    }

    prim(n);
}
