#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define INF 10'007

int n, k, dp[1002][1002];

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if (!j || i == j) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % INF;
        }
    cout << dp[n][k] % INF;
    return 0;
}
