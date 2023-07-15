#include<bits/stdc++.h>

using namespace std;

int t, n, m, dp[32][32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 30; i++) dp[i][i] = 1;
    for (int i = 1; i <= 31; i++) {
        for (int j = 1; j <= 31; j++) {
            if (i == j) continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << dp[n + 1][m + 1] << '\n';
    }
    return 0;
}
