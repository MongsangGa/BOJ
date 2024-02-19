#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE (int)5e6+2
// "어떤 수에 XOR 연산을 짝수번 하면 그대로다"

int n, m, stree[SIZE * 4], lazy[SIZE * 4];

void update_lazy(int node, int s, int e) {
    if (lazy[node]) {
        if ((e - s + 1) % 2) stree[node] ^= lazy[node];
        if (s != e) lazy[node * 2] ^= lazy[node], lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int s, int e, int fS, int fE, int diff) {
    update_lazy(node, s, e);
    if (s > fE || e < fS) return;
    if (s >= fS && e <= fE) {
        if ((e - s + 1) % 2) stree[node] ^= diff;
        if (s != e) lazy[node * 2] ^= diff, lazy[node * 2 + 1] ^= diff;
        return;
    }
    int mid = (s + e) / 2;
    update_range(node * 2, s, mid, fS, fE, diff);
    update_range(node * 2 + 1, mid + 1, e, fS, fE, diff);
    stree[node] = stree[node * 2] ^ stree[node * 2 + 1];
}

int query(int node, int s, int e, int fS, int fE) {
    update_lazy(node, s, e);
    if (s > fE || e < fS) return 0;
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, fS, fE) ^ query(node * 2 + 1, mid + 1, e, fS, fE);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        update_range(1, 0, n - 1, i, i, a);
    }
    cin >> m;
    while (m--) {
        int order, a, b, d;
        cin >> order >> a >> b;
        if (order & 1) {
            cin >> d;
            update_range(1, 0, n - 1, a, b, d);
        } else cout << query(1, 0, n - 1, a, b) << '\n';
    }
    return 0;
}
