#include <bits/stdc++.h>

using namespace std;

#define SIZE 17
int n, res, arr[SIZE][SIZE], dx[] = {0, 1, 1}, dy[] = {1, 1, 0};
// 가로, 대각선, 세로

void dfs(int dir, int x, int y) {
    if (x == n - 1 && y == n - 1) {
        res++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (dir == 0 && i == 2) continue;
        if (dir == 2 && i == 0) continue;
        int nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (i == 1 && (arr[x][y + 1] || arr[x + 1][y])) continue;
        dfs(i, nx, ny);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    dfs(0, 0, 1);
    cout << res;
    return 0;
}
