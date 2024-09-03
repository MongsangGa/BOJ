#include <bits/stdc++.h>

using namespace std;

vector<string> board;
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

struct info {
    int x, y, d;
};

bool BFS(int sx, int sy) {
    queue<info> q;
    bool vis[5][5] = {0};
    bool check = 1;
    q.push({sx,sy,0});
    vis[sx][sy] = 1;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=5||ny>=5) continue;
            if(vis[nx][ny]||board[nx][ny]=='X') continue;
            if(board[nx][ny] == 'P') {
                if(d+1 <= 2){
                    check = 0;
                    break;
                }
            }
            q.push({nx,ny,d+1});
            vis[nx][ny] = 1;
        }
        if(!check) break;
    }
    return check;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> res;
    for(auto p : places) {
        board = p;
        bool check = 1;
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) 
                if(board[i][j] == 'P')
                    if(!BFS(i,j)){
                        check = 0;
                        break;
                    }
            if(!check) break;
        }
        res.push_back(check);
    }
    return res;
}