#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int c, n, cost[1002], customer[1002], dp[100002];

int main() {
    fastio;
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> customer[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 100000; j++)
            if (j - cost[i] >= 0) dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);
    for (int i = 1; i <= 100000; i++)
        if (dp[i] >= c) {
            cout << i;
            return 0;
        }
    return 0;
}
