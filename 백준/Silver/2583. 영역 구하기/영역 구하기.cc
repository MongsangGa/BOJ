#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 101

int n, m, k, vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;
vector<int> res;

int main() {
    fastio;
    cin >> n >> m >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                vis[i][j] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            q.push({i, j});
            int ans = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int l = 0; l < 4; l++) {
                    int nx = x + dx[l], ny = y + dy[l];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx, ny});
                    ans++;
                }
            }
            res.push_back(ans + 1);
        }
    }
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for (auto r: res) cout << r << ' ';
    return 0;
}
