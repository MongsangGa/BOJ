#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1002
#define INF 10'007

int n, k, dp[SIZE][SIZE];

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 1; i < SIZE; i++)
        for (int j = 0; j <= i; j++) {
            if (!j || i == j) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % INF;
        }
    cout << dp[n][k];
    return 0;
}
