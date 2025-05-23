#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 112
int n, a[S][S], dx[] = {0, 1}, dy[] = {1, 0};
long long dp[S][S];

long long DFS(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == n - 1 && y == n - 1) return 1;
    dp[x][y] = 0;
    for (int i = 0; i < 2; i++) {
        int nx = x + (dx[i] * a[x][y]), ny = y + (dy[i] * a[x][y]);
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        dp[x][y] += DFS(nx, ny);
    }
    return dp[x][y];
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    fill(dp[0], dp[S], -1);
    cout << DFS(0, 0);
    return 0;
}
