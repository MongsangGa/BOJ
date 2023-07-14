#include<bits/stdc++.h>

using namespace std;

int t, n, m;

char arr[11][11];
int dp[11][11][1 << 11];

int solve(int x, int y, int state) {
    if (x == n) return 0;
    if (y == m) return solve(x + 1, 0, state);

    int &res = dp[x][y][state];
    if (dp[x][y][state] != -1) return res;

    res = 0;
    if (arr[x][y] == '.') {
        if (y == 0 && ~state & (1 << m - 2))
            res = max(res, 1 + solve(x, y + 1, (state << 1 | 1) & (1 << m + 1) - 1));
        if (y == m - 1 && ~state & 1 && ~state & 1 << m)
            res = max(res, 1 + solve(x, y + 1, (state << 1 | 1) & (1 << m + 1) - 1));;
        if (y > 0 && y < m - 1 && ~state & (1 << m - 2) && ~state & 1 && ~state & 1 << m)
            res = max(res, 1 + solve(x, y + 1, (state << 1 | 1) & (1 << m + 1) - 1));
    }
    res = max(res, solve(x, y + 1, state << 1 & (1 << m + 1) - 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 0) << '\n';
    }
    return 0;
}