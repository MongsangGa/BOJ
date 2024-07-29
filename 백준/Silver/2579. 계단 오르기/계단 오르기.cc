#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, arr[303], dp[303];

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
    cout << dp[n];
    return 0;
}
