#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t, n, m, w[22], dp[10'002];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        fill(dp, dp + 10'002, 0);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        cin >> m;
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (j - w[i] >= 0)
                    dp[j] += dp[j - w[i]];
        cout << dp[m] << '\n';
    }
    return 0;
}
