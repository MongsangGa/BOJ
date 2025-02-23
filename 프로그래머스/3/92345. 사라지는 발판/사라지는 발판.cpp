#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
int N, M;

bool C(int x, int y) {
    return x>=0 && y>=0 && x<N && y<M;
}

bool MOVE(vector<vector<int>> &board, int x, int y) {
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(C(nx,ny) && board[nx][ny]) 
            return 1;
    }
    return 0;
}

pair<bool, int> F(vector<vector<int>> &board, int x1, int y1, int x2 ,int y2) {
    if(!MOVE(board, x1, y1)) return {false, 0};
    
    pair<bool, int> ans = {false, 0};
    if(board[x1][y1]) {
        int MIN = 1e9, MAX = 0;
        for(int i=0;i<4;i++) {
            int nx = x1 + dx[i], ny = y1 + dy[i];
            if(!C(nx,ny) || !board[nx][ny]) continue;
            
            // BackTracking
            board[x1][y1] = 0;
            auto [win, cnt] = F(board, x2, y2, nx, ny);
            board[x1][y1] = 1;
            
            if(!win) {
                ans.first = true;
                MIN = min(MIN, cnt);
            }
            else {
                MAX = max(MAX, cnt);
            }
        }
        ans.second = ans.first ? MIN+1 : MAX+1;
    }
    return ans;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();
    return F(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}