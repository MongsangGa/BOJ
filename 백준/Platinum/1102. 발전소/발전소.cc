#include <bits/stdc++.h>

using namespace std;

#define MAX 16
#define INF 10000001

int n, cost[MAX][MAX], dp[1 << MAX], p, cntOn, state, res;
char c;

int solve(int now, int cnt) {
    if (cnt >= p) return 0;
    int &ret = dp[now];
    if (ret != INF) return ret;
    for (int i = 0; i < n; i++) {
        if (!(now & (1 << i))) continue; // now[i] != Y
        for (int j = 0; j < n; j++) {
            if (now & (1 << j)) continue; // now[j] == Y
            ret = min(ret, solve(now | (1 << j), cnt + 1) + cost[i][j]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'Y')
            ++cntOn, state |= (1 << i);
    }
    cin >> p;
    fill(dp, dp + (1 << MAX), INF);
    res = solve(state, cntOn);
    if (res >= INF) cout << "-1";
    else cout << res;
}
