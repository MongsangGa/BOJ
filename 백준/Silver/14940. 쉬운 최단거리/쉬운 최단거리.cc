#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 1'002

int n, m, arr[SIZE][SIZE], vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                q.push({i, j}), vis[i][j] = 1;
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || !arr[nx][ny]) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !vis[i][j]) cout << "-1 ";
            else cout << ((vis[i][j] - 1 == -1) ? 0 : vis[i][j] - 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
