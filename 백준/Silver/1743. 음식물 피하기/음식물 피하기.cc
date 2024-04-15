#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define S 103
int n, m, K, res, board[S][S], vis[S][S], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;

int main() {
    fastio;
    cin >> n >> m >> K;
    while (K--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] || !board[i][j]) continue;
            int cnt = 1;
            q.push({i, j}), vis[i][j] = 1;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k], ny = cur.second + dy[k];
                    if (nx <= 0 || ny <= 0 || nx >= n + 1 || ny >= m + 1 || vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny] = 1, cnt++;
                    q.push({nx, ny});
                }
            }
            res = max(res, cnt);
        }
    }
    cout << res;
    return 0;
}
