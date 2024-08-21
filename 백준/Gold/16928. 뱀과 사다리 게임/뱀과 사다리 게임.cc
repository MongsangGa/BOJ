#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, arr[SIZE], dp[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x] = y;
    }
    fill(dp, dp + SIZE, -1);
    q.push(1), dp[1] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int nxt = now + i;
            if (nxt > 100) continue;
            if (arr[nxt]) nxt = arr[nxt];
            if (dp[nxt] != -1) continue;
            q.push(nxt), dp[nxt] = dp[now] + 1;
        }
    }
    cout << dp[100];
    return 0;
}

