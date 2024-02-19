#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 10'002
#define INF 1e9

vector<int> adj[SIZE];
int n, m, a, ind[SIZE], cost[SIZE], res[SIZE], ans;
queue<int> q;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i] >> m;
        while (m--) {
            cin >> a;
            ind[i]++;
            adj[a].push_back(i);
        }
    }
    fill(res, res + SIZE, INF);
    for (int i = 1; i <= n; i++) {
        if (!ind[i])
            q.push(i);
        res[i] = cost[i];
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt: adj[cur]) {
            ind[nxt]--;
            res[nxt] = max(res[nxt], res[cur] + cost[nxt]);
            if (!ind[nxt])
                q.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, res[i]);
    cout << ans;
    return 0;
}
