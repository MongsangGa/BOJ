#include<bits/stdc++.h>

using namespace std;
#define SIZE 101

int n, maxM, maxC, m[SIZE], c[SIZE], dp[SIZE][SIZE * SIZE];

int main() {
    cin >> n >> maxM;
    for (int i = 1; i <= n; i++) cin >> m[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        maxC += c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxC; j++) {
            if (j - c[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    for (int j = 0; j <= maxC; j++) {
        if (dp[n][j] >= maxM) {
            cout << j;
            return 0;
        }
    }
    return 0;
}
