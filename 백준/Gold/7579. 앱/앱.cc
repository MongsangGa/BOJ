#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 105
int N, M, C, m[S], c[S], dp[S][S * S];

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> m[i];
    for (int i = 1; i <= N; i++) cin >> c[i], C += c[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= C; j++) {
            if (j - c[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    for (int i = 0; i <= C; i++)
        if (dp[N][i] >= M) {
            cout << i;
            return 0;
        }
    return 0;
}
