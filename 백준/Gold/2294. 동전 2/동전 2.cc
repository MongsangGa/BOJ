#include <bits/stdc++.h>

using namespace std;

int n, k, a, dp[10'002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    fill(dp, dp + 10002, 10002);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = a; j <= k; j++)
            dp[j] = min(dp[j], dp[j - a] + 1);
    }
    cout << (dp[k] == 10002 ? -1 : dp[k]);
    return 0;
}
