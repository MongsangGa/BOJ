#include <bits/stdc++.h>
using namespace std;
#define MAX 21
int n,arr[MAX][MAX],dist[MAX][MAX],check[MAX][MAX],res;
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
struct shark{
    int x, y, size, eat;
};
shark Bshark;
int eat(){
    memset(dist,0,sizeof(dist));
    memset(check,0,sizeof(check));
    queue<pair<int,int>> q;
    vector<tuple<int,int,int>> is_able;
    q.push({Bshark.x,Bshark.y});
    check[Bshark.x][Bshark.y]=1;
    while(!q.empty()){
        int x,y; tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(check[nx][ny] || arr[nx][ny]>Bshark.size) continue;
            check[nx][ny]=1;
            q.push({nx,ny});
            dist[nx][ny]=dist[x][y]+1;
            if(arr[nx][ny] && arr[nx][ny]<Bshark.size)
                is_able.push_back({dist[nx][ny],nx,ny});
        }
    }
    if(!is_able.size()) return 0;
    // able
    sort(is_able.begin(),is_able.end());
    int dist,x,y; tie(dist,x,y)=is_able[0];
    res+=dist;
    arr[Bshark.x][Bshark.y]=0;
    Bshark.x=x, Bshark.y=y, Bshark.eat++;
    arr[x][y]=0;
    if(Bshark.size==Bshark.eat){
        Bshark.size++;
        Bshark.eat=0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9)
                Bshark={i,j,2,0};
        }
    }
    while(eat());
    cout<<res;
    return 0;
}