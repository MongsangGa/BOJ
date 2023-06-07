#include<bits/stdc++.h>

using namespace std;

int n, k;

vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    dp.resize(n + 1, n);
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i + (i / 2) <= n) dp[i + (i / 2)] = min(dp[i + (i / 2)], dp[i] + 1);
    }
    if (dp[n] > k) cout << "water";
    else cout << "minigimbob";
    return 0;
}
