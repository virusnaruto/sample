#include <bits/stdc++.h>
using namespace std;

class NQueen{
    int N;
    public:
    NQueen(){
        cout<<"Enter the number of Queens :";
        cin>>N;
    }

    void BackTrack(){
        vector<vector<int>>grid(N,vector<int>(N));

        Bsolve(0,grid);

    }

void BNB(){
    vector<vector<int>>grid(N,vector<int>(N));
    vector<int>col(N);
    vector<int>leftD(2*N-1);
    vector<int>rightD(2*N-1);

    BNBsolve(0,grid,col,leftD,rightD);

}


    void print(vector<vector<int>>&adj){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(adj[i][j]==1){
                    cout<<'Q';
                }
                else cout<<'.';
            }
            cout<<endl;
        }
        cout<<endl;
    }

    bool isSafe(int x,int y,vector<vector<int>>&grid){
        //check col
        for(int i=0;i<N;i++){
            if(grid[i][y]==1)return false;
        }

        //left diagonal
        int dx=x;
        int dy=y;
        while(dx>=0 && dy>=0){
            if(grid[dx][dy]==1)return false;
            dx--;
            dy--;
        }
        dx=x;
        dy=y;
        while(dx<N && dy<N){
            if(grid[dx][dy]==1)return false;
            dx++;
            dy++;
        }

        //right diagonal
        dx=x;
        dy=y;
        while(dx<N && dy>=0){
            if(grid[dx][dy]==1)return false;
            dx++;
            dy--;
        }
        dx=x;
        dy=y;
        while(dx>=0 && dy<N){
            if(grid[dx][dy]==1)return false;
            dx--;
            dy++;
        }

        return true;

    
    }

    void Bsolve(int row,vector<vector<int>>&grid){
        if(row>=grid.size()){
            cout<<"****** FOUND A SOLUTION ******";
            cout<<endl;
            print(grid);
            return;

        }

        for(int i=0;i<N;i++){
            if(isSafe(row,i,grid)){
                grid[row][i]=1;
                Bsolve(row+1,grid);
                grid[row][i]=0;
            }
        }
    }

    void BNBsolve(int row,vector<vector<int>>&grid,vector<int>&col,vector<int>&ld,vector<int>&rd){
        if(row>=N){
            print(grid);
            cout<<endl;
            return;
        }

        for(int i=0;i<N;i++){
            if(col[i]==0 && ld[row+i]==0 && rd[row-i+N-1]==0){
                col[i]=1;
                ld[row+i]=1;
                rd[row-i+N-1]=1;
                grid[row][i]=1;
                BNBsolve(row+1,grid,col,ld,rd);
                 col[i]=0;
                ld[row+i]=0;
                rd[row-i+N-1]=0;
                grid[row][i]=0;
            }
        }
    }

};



int main(){
    NQueen q;
    q.BNB();
}