#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, x, dp[44], res = 1, pre;

int main() {
    fastio;
    cin >> n >> m;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    for (int i = 0; i < m; i++) {
        cin >> x;
        res *= dp[x - pre - 1];
        pre = x;
    }
    cout << res * dp[n - x];
    return 0;
}

/*
 * 이 정도 DP 는 손으로 쓰다 보면 금방 규칙을 찾을 수 있으니 풀이 생략하겠습니다
 */
