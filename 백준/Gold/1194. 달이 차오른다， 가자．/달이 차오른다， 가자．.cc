#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 51

int n, m, res, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char arr[SIZE][SIZE];
bool vis[SIZE][SIZE][1 << 7];
queue<tuple<int, int, int>> q;

int BFS() {
    while (!q.empty()) {
        int qs = q.size();
        while (qs--) {
            auto [x, y, v] = q.front();
            q.pop();
            if (arr[x][y] == '1') return res;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '#') continue;
                if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
                    int nv = v | (1 << (arr[nx][ny] - 'a'));
                    if (vis[nx][ny][nv]) continue;
                    vis[nx][ny][nv] = true;
                    q.push({nx, ny, nv});
                } else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
                    if (!vis[nx][ny][v] && v & (1 << (arr[nx][ny] - 'A')))
                        vis[nx][ny][v] = true, q.push({nx, ny, v});
                } else if (!vis[nx][ny][v])
                    vis[nx][ny][v] = true, q.push({nx, ny, v});
            }
        }
        res++;
    }
    return -1;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0')
                q.push({i, j, 0}), vis[i][j][0] = true;
        }
    }
    cout << BFS();
    return 0;
}
