#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
string s[SIZE];
queue<pair<int, int>> q;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    fill(vis[0], vis[SIZE - 1], 1e9);
    q.push({0, 0}), vis[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '0' || vis[nx][ny] <= vis[x][y] + 1)
                continue;
            q.push({nx, ny}), vis[nx][ny] = vis[x][y] + 1;
        }
    }
    cout << vis[n - 1][m - 1];
    return 0;
}

