#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S ((int)1e6+1)
int n, dp[S];

int f(int n) {
    if (dp[n] != 1e9) return dp[n];
    if (n == 1) return 0;
    if (n % 3 == 0) dp[n] = min(dp[n], f(n / 3) + 1);
    if (n % 2 == 0) dp[n] = min(dp[n], f(n / 2) + 1);
    dp[n] = min(dp[n], f(n - 1) + 1);
    return dp[n];
}

int main() {
    fastio;
    cin >> n;
    fill(dp, dp + S, 1e9);
    cout << f(n);
    return 0;
}
