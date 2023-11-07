#include <bits/stdc++.h>

using namespace std;

int n, dp[100'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i <= n; i++) 
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    cout << dp[n];
    return 0;
}
