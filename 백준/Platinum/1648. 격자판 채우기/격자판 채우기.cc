#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MOD 9901
#define SIZE 15

int n, m, dp[SIZE * SIZE][1 << SIZE];

int solve(int idx, int s) {
    if (idx == n * m && !s) return 1;
    if (idx > n * m) return 0;
    int &cur = dp[idx][s];
    if (cur != -1) return cur;
    cur = 0;
    if (s & 1) return cur = solve(idx + 1, s >> 1);
    cur = solve(idx + 1, (s >> 1) | (1 << (m - 1)));
    if ((idx + 1) % m && !(s & 2)) cur += solve(idx + 2, s >> 2);
    return cur % MOD;
}

int main() {
    fastio;
    cin >> n >> m;
    fill(dp[0], dp[SIZE * SIZE - 1], -1);
    cout << solve(0, 0);
    return 0;
}
