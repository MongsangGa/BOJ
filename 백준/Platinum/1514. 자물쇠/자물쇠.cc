#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
int n, a[102], b[102], dp[102][10][10][10][2];

int calc(int x) {
    while (x < 0) x += 10;
    return x % 10;
}

int solve(int idx, int x, int y, int z, int r) {
    if (idx == n) return 0;
    int &now = dp[idx][x][y][z][r];
    if (now != -1) return now;
    if (calc(x + a[idx]) == b[idx])
        return min(solve(idx + 1, y, z, 0, 0), solve(idx + 1, y, z, 0, 1));
    now = 1e9;
    for (int i = 1; i <= 3; i++) {
        if (r) {
            now = min(now, 1 + solve(idx, calc(x + i), y, z, r));
            now = min(now, 1 + solve(idx, calc(x + i), calc(y + i), z, r));
            now = min(now, 1 + solve(idx, calc(x + i), calc(y + i), calc(z + i), r));
        } else {
            now = min(now, 1 + solve(idx, calc(x - i), y, z, r));
            now = min(now, 1 + solve(idx, calc(x - i), calc(y - i), z, r));
            now = min(now, 1 + solve(idx, calc(x - i), calc(y - i), calc(z - i), r));
        }
    }
    return now;
}

int main() {
    // fastio;
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%1d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%1d", &b[i]);
    int res = min(solve(0, 0, 0, 0, 0), solve(0, 0, 0, 0, 1));
    printf("%d", res);
    return 0;
}
