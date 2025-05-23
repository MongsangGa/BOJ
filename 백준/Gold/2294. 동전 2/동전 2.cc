#include <bits/stdc++.h>

using namespace std;

int n, k, a[202], dp[200'002];

int main() {
    cin >> n >> k;
    fill(dp, dp + 200'002, 1e9);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
    if (dp[k] == 1e9) cout << -1;
    else cout << dp[k];
    return 0;
}
