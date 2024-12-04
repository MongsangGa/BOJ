#include <bits/stdc++.h>
using namespace std;
#define S 20'002
pair<int, int> dp[S];
int t, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, 0, sizeof dp);
        queue<int> q;
        q.push(1);
        dp[1] = {-1, -1};
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            if (!now) break;
            int nxt = now * 10 % n;
            if (!dp[nxt].first) {
                dp[nxt] = {now, 0};
                q.push(nxt);
            }
            nxt = (now * 10 + 1) % n;
            if (!dp[nxt].first) {
                dp[nxt] = {now, 1};
                q.push(nxt);
            }
        }
        string res;
        for (auto now = dp[0]; now.first != -1; now = dp[now.first])
            res += to_string(now.second);
        res += '1';
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }

    return 0;
}
