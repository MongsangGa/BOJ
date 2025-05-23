#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 500

int n, m, a[S][S], dp[S][S], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int DFS(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == n - 1 && y == m - 1) return 1;
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (a[x][y] <= a[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        dp[x][y] += DFS(nx, ny);
    }
    return dp[x][y];
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    fill(dp[0], dp[S], -1);
    cout << DFS(0, 0);
    return 0;
}
