#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    int v;
    vector<int> par,rank,size;

    DisjointSet(int s){
        v=s;
        par = vector<int>(s+1);
        rank = vector<int>(s+1);
        size = vector<int>(s+1,1);
        for(int i=0;i<=s;i++){
            par[i]=i;
        }
    }

    int findUPar(int x){
        if(par[x]==x)return x;
        return par[x] = findUPar(par[x]);
    }

    void unionBySize(int u,int v){
        int ultU = findUPar(u);
        int ultV = findUPar(v);
        if(ultU==ultV)return;
        if(size[ultU]<=size[ultV]){
            par[ultU]=ultV;
            size[ultV]+=size[ultU];
        }
        else{
            par[ultV]=ultU;
            size[ultU]+=size[ultV];
        }
    }

    void unionByRank(int u,int v){
         int ultU = findUPar(u);
        int ultV = findUPar(v);
        if(ultU==ultV)return;
        if(rank[ultU]<rank[ultV]){
            par[ultU]=ultV;
            rank[ultV]+=rank[ultU];
        }
        else if(rank[ultV]<rank[ultU]){
             par[ultV]=ultU;
            rank[ultU]+=rank[ultV];
        }
        else{
            par[ultU]=ultV;
            rank[ultV]++;
        }
    }

};

class Graph{
    int v;
    vector<vector<vector<int>>>adj;
    vector<vector<int>>edges;
    DisjointSet *st;
    public:
    Graph(){
        cout<<"Enter the number of vertices :";
        cin>>v;
        adj = vector<vector<vector<int>>>(v);
        st = new DisjointSet(v);
        while(true){
            int u,v,w;
            cout<<"Enter vertex 1 :";
            cin>>u;
            cout<<"Enter vertex 2 :";
            cin>>v;
            cout<<"Enter weight :";
            cin>>w;
            if(u==-1 || v==-1)break;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            edges.push_back({w,u,v});
        }
    }


    void Kruskal(){
       sort(edges.begin(),edges.end());
       int weight=0;
       for(int i=0;i<edges.size();i++){
        int w = edges[i][0];
        int u=edges[i][1];
        int v=edges[i][2];
        u = st->findUPar(u);
        v = st->findUPar(v);
        if(u!=v){
            weight+=w;
            st->unionBySize(u,v);
        }
       }
       cout<<weight<<endl;
    }



};


int main(){
    Graph g;
    g.Kruskal();
}