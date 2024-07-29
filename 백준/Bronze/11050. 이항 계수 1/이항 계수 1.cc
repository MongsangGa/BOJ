#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, dp[12][12];

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if (!j || i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    cout << dp[n][k];
    return 0;
}
