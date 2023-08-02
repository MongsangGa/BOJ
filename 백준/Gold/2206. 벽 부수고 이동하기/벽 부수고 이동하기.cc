#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int n, m, dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0}, dist[MAX][MAX][2];
queue<tuple<int, int, int>> q;
pair<int, int> x;
string arr[MAX];

int solve() {
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int x, y, wall;
        tie(x, y, wall) = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) return dist[x][y][wall];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (dist[nx][ny][wall] || nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == '0') {
                dist[nx][ny][wall] = dist[x][y][wall] + 1;
                q.push({nx, ny, wall});
            } else if (arr[nx][ny] == '1' && !wall) {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve();
    return 0;
}
