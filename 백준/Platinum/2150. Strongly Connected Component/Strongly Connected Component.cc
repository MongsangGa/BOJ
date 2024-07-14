#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
const int SIZE = 10'005;
int v, e, len;
bool vis[SIZE];
stack<int> s;
vector<int> adj[SIZE], radj[SIZE];
vector<int> res[SIZE];

void DFS(int now) {
    vis[now] = true;
    for (auto nxt: adj[now]) {
        if (vis[nxt]) continue;
        DFS(nxt);
    }
    s.push(now);
}

void rDFS(int now) {
    vis[now] = true;
    res[len].push_back(now);
    for (auto nxt: radj[now]) {
        if (vis[nxt]) continue;
        rDFS(nxt);
    }
}


int main() {
    fastio;
    cin >> v >> e;
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    for (int i = 1; i <= v; i++)
        if (!vis[i])
            DFS(i);
    fill(vis, vis + SIZE, 0);
    while (!s.empty()) {
        int now = s.top();
        s.pop();
        if (vis[now]) continue;
        rDFS(now);
        len++;
    }
    for (int i = 0; i < len; i++)
        sort(res[i].begin(), res[i].end());
    sort(res, res + len, [&](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        for (auto j: res[i])
            cout << j << ' ';
        cout << "-1\n";
    }
    return 0;
}
