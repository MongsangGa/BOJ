#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

struct info{
  int x, y, c;  
};

info s, e;
queue<info> q;
bool vis[SIZE][SIZE];
int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};

int solution(vector<string> board) {
    int answer = 1e9, n = board.size(), m = board[0].size();
    fastio;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='R') s = {i,j,0};
            if(board[i][j]=='G') e = {i,j,0};
        }
    }
    q.push(s), vis[s.x][s.y] = 1;
    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        if(now.x == e.x && now.y == e.y)
            answer = min(answer, now.c);
        for(int i=0;i<4;i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny]=='D') continue;
            while(1) {
                nx += dx[i], ny += dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny]=='D') {
                    nx -= dx[i], ny -= dy[i];
                    break;
                }
            }
            if(vis[nx][ny]) continue;
            q.push({nx,ny,now.c+1}), vis[nx][ny]=1;
        }
    }
    if(answer == 1e9) answer = -1;
    return answer;
}