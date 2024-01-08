#include <bits/stdc++.h>

using namespace std;

int n, dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dp[1] = dp[3] = dp[4] = 1;
    for (int i = 5; i <= n; i++) {
        if (dp[i - 1] && dp[i - 3] && dp[i - 4]) dp[i] = 0;
        else dp[i] = 1;
    }
    cout << (dp[n] ? "SK" : "CY");
    return 0;
}
