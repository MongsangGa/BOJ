#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, t, k[1002], s[1002], dp[102][10002];

int main() {
    fastio;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> k[i] >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 10000; j++) {
            if (j - k[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k[i]] + s[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][t];
    return 0;
}
