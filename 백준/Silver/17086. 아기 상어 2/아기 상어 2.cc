#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

#define SIZE 51
#define INF 2501
int n, m, res, a, vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
queue<pair<int, int>> q;

int main() {
    fastio
    cin >> n >> m;
    fill(vis[0], vis[SIZE - 1], INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (a) q.push({i, j}), vis[i][j] = 0;
        }
    }
    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            auto [x, y] = q.front();
            q.pop();
            for (int j = 0; j < 8; j++) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] != INF) continue;
                vis[nx][ny] = vis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == INF) continue;
            res = max(res, vis[i][j]);
        }
    }
    cout << res;
    return 0;
}
