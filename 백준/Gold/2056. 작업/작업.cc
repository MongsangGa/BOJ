#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 10'002

int n, ind[SIZE], cost[SIZE], ans[SIZE], res;
vector<int> adj[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n;
    int len, y;
    for (int x = 1; x <= n; x++) {
        cin >> cost[x] >> len;
        while (len--) {
            cin >> y;
            adj[y].push_back(x);
            ++ind[x];
        }
    }
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            q.push(i), ans[i] = cost[i];
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (auto nxt: adj[now]) {
            --ind[nxt];
            ans[nxt] = max(ans[nxt], ans[now] + cost[nxt]);
            if (!ind[nxt])
                q.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++)
        res = max(res, ans[i]);
    cout << res;
    return 0;
}
