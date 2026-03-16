#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct Edge{
    int u,v,w;
};

int parent[MAX];

int finde(int x){
    if(parent[x]==x)
        return x;
    return parent[x]=finde(parent[x]);
}

void unione(int a,int b){
    int pa=finde(a);
    int pb=finde(b);
    parent[pb]=pa;
}

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int kruskal(Edge edges[], int n, int e){

    sort(edges, edges+e, cmp);

    for(int i=0;i<n;i++)
        parent[i]=i;

    int mincost=0, edgecount=0;

    for(int i=0;i<e && edgecount<n-1;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;

        if(finde(u)!=finde(v)){
            cout<<u<<" - "<<v<<" : "<<w<<endl;
            mincost+=w;
            edgecount++;
            unione(u,v);
        }
    }

    return mincost;
}

int main(){

    Edge edges[MAX];
    int n,e;

    cout<<"Enter n & e: ";
    cin>>n>>e;

    cout<<"Enter edges (u v w):"<<endl;

    for(int i=0;i<e;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }

    int cost=kruskal(edges,n,e);

    cout<<"Minimum cost = "<<cost;

    return 0;
}
