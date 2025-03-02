#include<bits/stdc++.h>
using namespace std;
#define S 102

int n, m, vis[S][S];
int dx[] = {0,-1,0,1}, dy[]={-1,0,1,0};
queue<pair<int,int>> q;

void BFS(vector<vector<int>> &maps) {
    q.push({0,0}), vis[0][0] = 1;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||!maps[nx][ny]||vis[nx][ny]) continue;
            q.push({nx,ny}), vis[nx][ny] = vis[x][y] + 1;
        }
    }
}

int solution(vector<vector<int> > maps){
    n = maps.size(), m = maps[0].size();
    BFS(maps);
    if(vis[n-1][m-1]) return vis[n-1][m-1];
    else return -1;
}