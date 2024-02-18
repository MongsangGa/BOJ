#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long int
#define SIZE 100'002
ll arr[SIZE], stree[SIZE * 4], lazy[SIZE * 4];

ll init(int node, int s, int e) {
    if (s == e) return stree[node] = arr[s];
    int mid = (s + e) / 2;
    return stree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

void update_lazy(int node, int s, int e) {
    if (lazy[node]) {
        stree[node] += (e - s + 1) * lazy[node];
        if (s != e)
            lazy[node * 2] += lazy[node], lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;

}

void update_range(int node, int s, int e, int fS, int fE, int diff) {
    update_lazy(node, s, e);
    if (s > fE || e < fS) return;
    if (s >= fS && e <= fE) {
        stree[node] += (e - s + 1) * diff;
        if (s != e)
            lazy[node * 2] += diff, lazy[node * 2 + 1] += diff;
        return;
    }
    int mid = (s + e) / 2;
    update_range(node * 2, s, mid, fS, fE, diff);
    update_range(node * 2 + 1, mid + 1, e, fS, fE, diff);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

ll query(int node, int s, int e, int idx) {
    update_lazy(node, s, e);
    if (s > idx || e < idx) return 0;
    if (s == e) return stree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, idx) + query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
    fastio;
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    cin >> m;
    while (m--) {
        int order, a, b, d;
        cin >> order;
        if (order == 1) {
            cin >> a >> b >> d;
            update_range(1, 1, n, a, b, d);
        } else {
            cin >> a;
            cout << query(1, 1, n, a) << '\n';
        }
    }
    return 0;
}
