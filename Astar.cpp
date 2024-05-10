#include <bits/stdc++.h>
using namespace std;

class State{
    public:
    vector<vector<int>>grid;
    int heu,lvl,fn;
    public:
    State(){
        grid = vector<vector<int>>(3,vector<int>(3,0));
        heu=lvl=fn=0;
    }
    State(vector<vector<int>>&g,int h,int l,int f){
        this->grid = g;
        heu=h;
        lvl=l;
        fn=f;
    }

    int calci(State &state,State &final){
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(state.grid[i][j]==0)continue;
            else if(state.grid[i][j]!=final.grid[i][j])cnt++;
        }
    }
    state.heu = cnt;
    return state.fn= state.lvl+cnt;
}





    void solve(){
        cout<<"Enter initial state :"<<endl;
        State init;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>init.grid[i][j];
            }
        }
        cout<<endl;
        cout<<"Enter final state :"<<endl;
        State finals;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>finals.grid[i][j];
            }
        }
    
        vector<pair<int,State>>pq;

        pq.push_back({calci(init,finals),init});

        while(!pq.empty()){
            sort(pq.begin(),pq.end(),[&](pair<int,State>&a,pair<int,State>&b){
                return a.first<b.first;
            });
            cout<<"##############################################################"<<endl;
            cout<<"Selected State :"<<endl;
            int fn = (pq.begin())->first;
            State st = (pq.begin())->second;
            pq.erase(pq.begin());
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<st.grid[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"f(n):"<<st.fn<<endl;
            cout<<"h(n):"<<st.heu<<endl;
            cout<<"lvl:"<<st.lvl<<endl;
            if(st.grid==finals.grid){
                cout<<"Reached the final state !"<<endl;
                break;
            }

            cout<<endl;
            cout<<"Possible States are :"<<endl;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            int sx,sy;
            for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(st.grid[i][j]==0){
                            sx=i;
                            sy=j;
                            break;
                        }
                    }
                }

            for(int k=0;k<4;k++){
                State temp = st;
                int xx = dx[k]+sx;
                int yy = dy[k]+sy;
                if(xx>=0 && xx<3 && yy>=0 && yy<3){
                    swap(temp.grid[xx][yy],temp.grid[sx][sy]);

                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            cout<<temp.grid[i][j]<<" ";
                        }
                        cout<<endl;
                    }

                    temp.lvl = st.lvl+1;
                    pq.push_back({calci(temp,finals),temp});
                        cout<<"f(n):"<<temp.fn<<endl;
                        cout<<"h(n):"<<temp.heu<<endl;
                        cout<<"lvl:"<<temp.lvl<<endl;
                    cout<<endl;
                    cout<<"-------------------------"<<endl;    
                }
            }

            cout<<"##############################################################"<<endl;
        }
    
    }




};








int main(){
    State st;
    st.solve();
}