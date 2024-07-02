#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int, int>
#define x first
#define y second
#define SIZE 32
#define INF 1e9
char arr[SIZE][SIZE][SIZE];
int l, n, m, vis[SIZE][SIZE][SIZE], dl[3] = {-1, 0, 1}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
pair<int, pii > s, e;
queue<pair<int, pii > > q;

int main() {
    fastio;
    while (1) {
        cin >> l >> n >> m;
        if (!l && !n && !m) break;
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> arr[k][i][j];
                    if (arr[k][i][j] == 'S') s = {k, {i, j}};
                    if (arr[k][i][j] == 'E') e = {k, {i, j}};
                }
            }
        }
        fill(vis[0][0], vis[SIZE - 1][SIZE - 1], INF);
        vis[s.x][s.y.x][s.y.y] = 0;
        q.push({s.x, {s.y.x, s.y.y}});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 3; i++) {
                int nl = cur.x + dl[i];
                if (nl < 0 || nl >= l || arr[nl][cur.y.x][cur.y.y] == '#' || vis[nl][cur.y.x][cur.y.y] != INF) continue;
                q.push({nl, {cur.y.x, cur.y.y}});
                vis[nl][cur.y.x][cur.y.y] = vis[cur.x][cur.y.x][cur.y.y] + 1;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur.y.x + dx[i], ny = cur.y.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[cur.x][nx][ny] == '#' ||
                    vis[cur.x][nx][ny] != INF)
                    continue;
                q.push({cur.x, {nx, ny}});
                vis[cur.x][nx][ny] = vis[cur.x][cur.y.x][cur.y.y] + 1;
            }
        }
        if (vis[e.x][e.y.x][e.y.y] == INF) cout << "Trapped!\n";
        else cout << "Escaped in " << vis[e.x][e.y.x][e.y.y] << " minute(s).\n";
    }
    return 0;
}
