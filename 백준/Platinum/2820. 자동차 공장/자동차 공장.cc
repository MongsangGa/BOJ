#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 500'002

int n, a, x, m, num, stree[SIZE * 4], lazy[SIZE * 4], arr[SIZE], S[SIZE], E[SIZE];
vector<int> adj[SIZE];

void DFS(int now) {
    S[now] = ++num;
    for (auto nxt: adj[now]) {
        if (S[nxt]) continue;
        DFS(nxt);
    }
    E[now] = num;
}

void updateLazy(int node, int s, int e) {
    if (lazy[node]) {
        stree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

int update(int fS, int fE, int c, int node = 1, int s = 1, int e = n) {
    updateLazy(node, s, e);
    if (s > fE || e < fS) return stree[node];
    if (fS <= s && e <= fE) {
        stree[node] += (e - s + 1) * c;
        if (s != e) lazy[node * 2] += c, lazy[node * 2 + 1] += c;
        return stree[node];
    }
    int mid = (s + e) / 2;
    return stree[node] = update(fS, fE, c, node * 2, s, mid) + update(fS, fE, c, node * 2 + 1, mid + 1, e);
}

int query(int fS, int fE, int node = 1, int s = 1, int e = n) {
    updateLazy(node, s, e);
    if (e < fS || s > fE) return 0;
    if (fS <= s && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return query(fS, fE, node * 2, s, mid) + query(fS, fE, node * 2 + 1, mid + 1, e);
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i != 1) cin >> x, adj[x].push_back(i);
    }
    DFS(1);
    for (int i = 1; i <= n; i++) update(S[i], S[i], arr[i]);
    while (m--) {
        char order;
        cin >> order;
        if (order == 'p') {
            cin >> a >> x;
            if (S[a] == E[a]) continue;
            update(S[a] + 1, E[a], x);
        } else {
            cin >> a;
            cout << query(S[a], S[a]) << '\n';
        }
    }
    return 0;
}
