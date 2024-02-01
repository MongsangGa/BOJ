#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 1002
int n, m, res, board[SIZE][SIZE], vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;

bool Check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j])
                return false;
    return true;
}

int main() {
    fastio;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
                vis[i][j] = 1;
            } else if (board[i][j] == -1) vis[i][j] = 1;
        }
    }
    while (!q.empty()) {
        res++;
        int len = q.size();
        for (int l = 0; l < len; l++) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (!Check()) cout << -1;
    else cout << res - 1;
    return 0;
}
