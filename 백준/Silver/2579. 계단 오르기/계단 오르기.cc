#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 309
int n, a[S], dp[S];

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 3] + a[i - 1], dp[i - 2]) + a[i];
    cout << dp[n];
    return 0;
}
