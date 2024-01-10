#include <bits/stdc++.h>

using namespace std;

//  현재 위치, 이동횟수, 시간
int t, w, arr[1001], dp[2][31][1001], res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> arr[i];
    for (int i = 0; i <= w; i++) {
        for (int j = 1; j <= t; j++) {
            if (!i) dp[0][i][j] = dp[0][i][j - 1] + (arr[j] == 1);
            else {
                dp[0][i][j] = max(dp[0][i][j - 1] + (arr[j] == 1), dp[1][i - 1][j - 1] + (arr[j] == 1));
                dp[1][i][j] = max(dp[1][i][j - 1] + (arr[j] == 2), dp[0][i - 1][j - 1] + (arr[j] == 2));
            }
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= w; j++)
            res = max(res, dp[i][j][t]);
    cout << res;
    return 0;
}
