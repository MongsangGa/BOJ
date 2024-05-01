#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 102

int n, m, k, len, res, dp[SIZE][SIZE][82], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
string s;
char board[SIZE][SIZE];

int DFS(int x, int y, int depth) {
    int &cur = dp[x][y][depth];
    if (cur != -1) return cur;
    if (depth == len) return 1;
    cur = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = x + (dx[j] * i), ny = y + (dy[j] * i);
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == s[depth + 1])
                cur += DFS(nx, ny, depth + 1);
        }
    }
    return cur;
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    cin >> s;
    len = s.size() - 1;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == s[0])
                res += DFS(i, j, 0);
    cout << res;
    return 0;
}
