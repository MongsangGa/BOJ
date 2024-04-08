#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 1001
int n, dp[SIZE][SIZE];
bool vis[SIZE];
vector<tuple<int, int, int>> arr;

int solve(int nowS, int nowI) {
    int &now = dp[nowS][nowI];
    if (now != -1) return now;
    int cnt = 0, sum = 0;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        auto [nxtS, nxtI, c] = arr[i];
        if (nowS >= nxtS || nowI >= nxtI) {
            if (!vis[i])
                vis[i] = true, sum += c, idx.push_back(i);
            cnt++;
        }
    }
    now = cnt;
    for (auto s = nowS; s <= min(1000, nowS + sum); s++)
        now = max(now, solve(s, min(1000, nowI + (sum - (s - nowS)))));
    for (auto i: idx)
        vis[i] = false;
    return now;
}

int main() {
    fastio;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
    memset(dp, -1, sizeof dp);
    cout << solve(1, 1);
    return 0;

}
