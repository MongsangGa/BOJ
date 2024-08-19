#include <bits/stdc++.h>

using namespace std;

#define MAX 501

int n, m, arr[MAX][MAX], dp[MAX][MAX], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int solve(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] >= arr[x][y] || nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        dp[x][y] += solve(nx, ny);
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}
