#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 1'000'001
#define INF 1'000'000'009
long long int t, n, dp[SIZE];

int main() {
    fastio;
    dp[0] = dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < SIZE; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % INF;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
