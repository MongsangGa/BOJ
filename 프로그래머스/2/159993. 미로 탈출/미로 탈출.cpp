#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define SIZE 102

int n, m, dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
vector<string> board;

int BFS(pii s, pii e) {
    queue<pii> q;
    int vis[SIZE][SIZE];
    fill(vis[0], vis[SIZE-1], -1);
    q.push(s), vis[s.first][s.second] = 0;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if(x == e.first && y == e.second) 
            return vis[x][y];
        for(int i=0;i<4;i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||board[nx][ny]=='X'||vis[nx][ny]!=-1) continue;
            q.push({nx,ny}), vis[nx][ny] = vis[x][y] + 1;
        }
    }
    return -1;
}


int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size(), m = maps[0].size(), board = maps;
    pii s, e, l;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j] == 'S') s = {i,j};
            if(board[i][j] == 'E') e = {i,j};
            if(board[i][j] == 'L') l = {i,j};
        }
    }
    int one = BFS(s,l);
    int two = BFS(l,e);
    if(one == -1 || two == -1) answer = -1;
    else answer = one + two;
    return answer;
}