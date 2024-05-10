#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    vector<vector<vector<int>>>adj;
    Graph(){
        cout<<"Enter the number of vertices :";
        cin>>v;
        adj = vector<vector<vector<int>>>(v);
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
        }
    }

    void prims(){
        cout<<"Enter any vertex :";
        int src;
        cin>>src;
        vector<int>visit(v);
        vector<vector<int>>ans(v,vector<int>(v));
        int weight=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        //wt src prt
        pq.push({0,src,-1});
        while(!pq.empty()){
            int wt = pq.top()[0];
            src = pq.top()[1];
            int parent = pq.top()[2];
            pq.pop();
            if(visit[src]==1)continue;
            weight+=wt;
            visit[src]=1;
            if(parent!=-1){
            ans[src][parent]=ans[parent][src]=wt;
            }
            for(auto it:adj[src]){
                if(visit[it[0]]==0){
                    pq.push({it[1],it[0],src});
                }
            }
        }
        cout<<weight<<endl;
    }


};


int main(){
    Graph g;
    g.prims();
}