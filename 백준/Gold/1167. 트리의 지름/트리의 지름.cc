#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 100'001

int v, res = -INT_MAX, target;
bool vis[SIZE];
vector<pair<int, int>> adj[SIZE];

void DFS(int now, int sum) {
    vis[now] = true;
    if (res < sum)
        res = sum, target = now;
    for (auto nxt: adj[now]) {
        if (vis[nxt.first]) continue;
        DFS(nxt.first, sum + nxt.second);
    }
}

int main() {
    fastio;
    cin >> v;
    while (v--) {
        int now, next, cost;
        cin >> now;
        while (1) {
            cin >> next;
            if (next == -1) break;
            cin >> cost;
            adj[now].push_back({next, cost});
        }
    }
    DFS(1, 0);
    fill(vis, vis + SIZE, 0);
    DFS(target, 0);
    cout << res;
    return 0;
}
