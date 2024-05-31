#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 128
int t, n, arr[SIZE][SIZE], dis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;

int main() {
    fastio;
    while (++t) {
        cin >> n;
        if (!n) break;
        fill(arr[0], arr[SIZE - 1], 0);
        fill(dis[0], dis[SIZE - 1], 1e9);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        q.push({0, 0}), dis[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || dis[nx][ny] <= dis[x][y] + arr[x][y]) continue;
                q.push({nx, ny});
                dis[nx][ny] = dis[x][y] + arr[x][y];
            }
        }
        cout << "Problem " << t << ": " << dis[n - 1][n - 1] + arr[n - 1][n - 1] << '\n';
    }
    return 0;
}
