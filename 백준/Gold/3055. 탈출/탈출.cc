#include <bits/stdc++.h>

using namespace std;
#define SIZE 52
int n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
bool vis[SIZE][SIZE];
char board[SIZE][SIZE];
pair<int, int> d;
queue<pair<int, int>> s, w;

int BFS() {
    int t = 0;
    while (!s.empty()) {
        int wSize = w.size();
        for (int i = 0; i < wSize; i++) {
            auto now = w.front();
            w.pop();
            for (int j = 0; j < 4; j++) {
                int nx = now.first + dx[j], ny = now.second + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == '*' || board[nx][ny] == 'X' ||
                    board[nx][ny] == 'D')
                    continue;
                w.push({nx, ny});
                board[nx][ny] = '*';
            }
        }
        int sSize = s.size();
        for (int i = 0; i < sSize; i++) {
            auto now = s.front();
            s.pop();
            if (now == d) return t;
            for (int j = 0; j < 4; j++) {
                int nx = now.first + dx[j], ny = now.second + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || board[nx][ny] == '*' ||
                    board[nx][ny] == 'X')
                    continue;
                s.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
        t++;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') s.push({i, j}), vis[i][j] = 1;
            else if (board[i][j] == '*') w.push({i, j});
            else if (board[i][j] == 'D') d = {i, j};
        }
    }
    int res = BFS();
    if (res == -1) cout << "KAKTUS";
    else cout << res;
    return 0;
}
