#include <bits/stdc++.h>
using namespace std;
int n,m,arr[501][501],nx[4]={-1,0,1,0},ny[4]={0,-1,0,1},len=0,cnt=0,MAX=0;
bool visit[501][501];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j] || arr[i][j]==0) continue;
            queue<pair<int,int> > q;
            q.push({i,j});
            visit[i][j]=true;
            len++;cnt=0;
            while(!q.empty()){
                int x,y;
                tie(x,y)=q.front();
                q.pop();
                cnt++;
                for(int i=0;i<4;i++){
                    int dx=x+nx[i],dy=y+ny[i];
                    if(dx<0 || dy<0 || dx>=n || dy>=m || visit[dx][dy]) continue;
                    if(arr[dx][dy]==1){
                        q.push({dx,dy});
                        visit[dx][dy]=true;
                    }
                }
            }
            MAX=max(MAX,cnt);
        }
    }
    cout<<len<<'\n'<<MAX;
    return 0;
}
