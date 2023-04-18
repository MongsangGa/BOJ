#include<bits/stdc++.h>
using namespace std;
#define M 1501
int R,C,Ei,Ej,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},res;
char arr[M][M];
bool swanchk[M][M],lakechk[M][M];
queue<pair<int ,int>> swan1,swan2,lake1,lake2;
void solve(){
    int a,b;
    while(!lake1.empty()){
        tie(a,b)=lake1.front(); lake1.pop();
        arr[a][b]='.';
        for(int i=0;i<4;i++){
            int x=dx[i]+a,y=dy[i]+b;
            if(x<0 || y<0 || x>=R || y>=C || lakechk[x][y] || arr[x][y]=='.') continue;
            if(arr[x][y]=='.') lake1.push({x,y});
            else lake2.push({x,y});
            lakechk[x][y]=1;
        }
    }
}
bool swan(){
    int a,b;
    while(!swan1.empty()){
        tie(a,b)=swan1.front(); swan1.pop();
        if(a==Ei && b==Ej) return 1;
        for(int i=0;i<4;i++){
            int x=dx[i]+a,y=dy[i]+b;
            if(x<0 || y<0 || x>=R || y>=C || swanchk[x][y]) continue;
            if(arr[x][y]=='.') swan1.push({x,y});
            else swan2.push({x,y});
            swanchk[x][y]=1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='L'){
                if(swan1.empty()) {
                    swan1.push({i,j});
                    swanchk[i][j]=1;
                }
                else Ei=i,Ej=j;
                arr[i][j]='.';
            }
            if(arr[i][j]=='.'){
                lake1.push({i,j});
                lakechk[i][j]=1;
            }
        }
    }
    while(1){
        solve();
        if(swan()) break;
        lake1=lake2, swan1=swan2;
        lake2=queue<pair<int,int>>();
        swan2=queue<pair<int,int>>();
        res++;
    }
    printf("%d",res);
    return 0;
}
