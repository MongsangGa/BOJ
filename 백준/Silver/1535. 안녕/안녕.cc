#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, dp[22][102], w[22], v[22];


int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            if (j - w[i] > 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][100];
    return 0;
}
