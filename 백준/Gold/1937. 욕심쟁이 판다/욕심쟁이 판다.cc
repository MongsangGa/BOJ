#include<bits/stdc++.h>

using namespace std;
#define SIZE 501
int n, res, arr[SIZE][SIZE], dp[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int DFS(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (arr[nx][ny] > arr[x][y])
            dp[x][y] = max(dp[x][y], 1 + DFS(nx, ny));
    }
    return dp[x][y];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            DFS(i, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res = max(res, dp[i][j]);
    cout << res;
    return 0;
}
