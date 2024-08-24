#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'002

int n, m, x, w, p[SIZE], res[SIZE];
vector<int> adj[SIZE];

void DFS(int now) {
    if (p[now] != -1)
        res[now] += res[p[now]];
    for (auto nxt: adj[now])
        DFS(nxt);
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == -1) continue;
        adj[p[i]].push_back(i);
    }
    while (m--) {
        cin >> x >> w;
        res[x] += w;
    }
    DFS(1);
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    return 0;
}

