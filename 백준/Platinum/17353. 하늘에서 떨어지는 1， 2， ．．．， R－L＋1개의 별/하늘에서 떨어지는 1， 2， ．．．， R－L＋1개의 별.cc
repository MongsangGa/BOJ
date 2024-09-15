#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define SIZE 100'005

int n, q;
ll arr[SIZE], stree[SIZE * 4], lazy[SIZE * 4];

void update_lazy(int node, int s, int e) {
    if (lazy[node]) {
        stree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int qs, int qe, int diff, int node = 1, int s = 1, int e = n) {
    update_lazy(node, s, e);
    if (s > qe || e < qs) return;
    if (qs <= s && e <= qe) {
        stree[node] += (e - s + 1) * diff;
        if (s != e) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (s + e) / 2;
    update(qs, qe, diff, node * 2, s, mid);
    update(qs, qe, diff, node * 2 + 1, mid + 1, e);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

ll query(int qs, int qe, int node = 1, int s = 1, int e = n) {
    update_lazy(node, s, e);
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return stree[node];
    int mid = (s + e) / 2;
    return query(qs, qe, node * 2, s, mid) + query(qs, qe, node * 2 + 1, mid + 1, e);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        update(i, i, arr[i] - arr[i - 1]);
    cin >> q;
    for (int i = 0, order, qs, qe, x; i < q; i++) {
        cin >> order;
        if (order == 1) {
            cin >> qs >> qe;
            update(qs, qe, 1);
            update(qe + 1, qe + 1, -(qe - qs + 1));
        } else {
            cin >> x;
            cout << query(1, x) << '\n';
        }
    }
    return 0;
}
