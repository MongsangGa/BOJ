#include <bits/stdc++.h>

using namespace std;
int n, t, a, w[32];
bool dp[32][80002];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    dp[0][40000] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 80000; j++) {
            if (!dp[i - 1][j]) continue;
            dp[i][j] = 1;
            if (j - w[i] >= 0) dp[i][j - w[i]] = 1;
            if (j + w[i] <= 80000) dp[i][j + w[i]] = 1;
        }
    }
    cin >> t;
    while (t--) {
        cin >> a;
        if (dp[n][a + 40000]) cout << "Y ";
        else cout << "N ";
    }
}
