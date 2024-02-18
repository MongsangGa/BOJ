#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'002
int n, m, order, a, b, stree[SIZE * 4], lazy[SIZE * 4];

// lazy[i] : 반전되는 횟수
void update_lazy(int node, int s, int e) {
    if (lazy[node] % 2) {
        stree[node] = e - s + 1 - stree[node];
        if (s != e)
            lazy[node * 2] = lazy[node * 2 + 1] += 1;
    }
    lazy[node] = 0;
}

void update_range(int node, int s, int e, int fS, int fE) {
    update_lazy(node, s, e);
    if (s > fE || e < fS) return;
    if (s >= fS && e <= fE) {
        stree[node] = e - s + 1 - stree[node];
        if (s != e)
            lazy[node * 2] = lazy[node * 2 + 1] += 1;
        return;
    }
    int mid = (s + e) / 2;
    update_range(node * 2, s, mid, fS, fE);
    update_range(node * 2 + 1, mid + 1, e, fS, fE);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

int query(int node, int s, int e, int fS, int fE) {
    update_lazy(node, s, e);
    if (s > fE || e < fS) return 0;
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, fS, fE) + query(node * 2 + 1, mid + 1, e, fS, fE);
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        cin >> order >> a >> b;
        if (!order) update_range(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << '\n';
    }
    return 0;
}
