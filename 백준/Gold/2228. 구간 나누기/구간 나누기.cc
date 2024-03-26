#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define INF -3276889
int N, M, arr[101], dp[101][101];

int solve(int n, int m) {
    if (m == 0) return 0;
    if (n <= 0) return INF;
    if (dp[n][m]) return dp[n][m];
    dp[n][m] = solve(n - 1, m);
    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += arr[i];
        int temp = solve(i - 2, m - 1) + sum;
        dp[n][m] = max(dp[n][m], temp);
    }
    return dp[n][m];
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cout << solve(N, M);
    return 0;
}
