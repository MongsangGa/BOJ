#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, c[5'005], p[5'005], dp[10'005];
double m;

int main() {
    fastio;
    while (1) {
        cin >> n >> m;
        int M = (int) ((m + 0.005) * 100);
        if (!n) break;
        fill(dp, dp + 10'005, 0);
        for (int i = 1; i <= n; i++) {
            double price;
            cin >> c[i] >> price;
            p[i] = (int) ((price + 0.005) * 100);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= M; j++) {
                if (j - p[i] >= 0)
                    dp[j] = max(dp[j], dp[j - p[i]] + c[i]);
            }
        cout << dp[M] << '\n';
    }
    return 0;
}
