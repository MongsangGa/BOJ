#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'002

int t, n, m, w, ind[SIZE], cost[SIZE], ans[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        fill(ind, ind + SIZE, 0);
        fill(cost, cost + SIZE, 0);
        fill(ans, ans + SIZE, 0);
        for (int i = 1; i <= n; i++)
            cin >> cost[i];
        while (m--) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            ++ind[y];
        }
        cin >> w;
        for (int i = 1; i <= n; i++)
            if (!ind[i])
                q.push(i), ans[i] = cost[i];
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int nxt: adj[now]) {
                --ind[nxt];
                if (!ind[nxt])
                    q.push(nxt);
                ans[nxt] = max(ans[nxt], ans[now] + cost[nxt]);
            }
        }
        cout << ans[w] << '\n';
    }
    return 0;
}
