#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define SIZE 32'003

int n, m, ind[SIZE];
vector<int> adj[SIZE];
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++ind[v];
    }
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            pq.push(i);
    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();
        cout << now << ' ';
        for (int nxt: adj[now]) {
            --ind[nxt];
            if (!ind[nxt])
                pq.push(nxt);
        }
    }
    return 0;
}
