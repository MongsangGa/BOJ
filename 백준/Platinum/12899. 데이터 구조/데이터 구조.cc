#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 2'000'000

int n, tree[S * 4 + 1];

void update(int idx, int node = 1, int s = 1, int e = S) {
    if (idx < s || idx > e) return;
    ++tree[node];
    if (s == e) return;
    int mid = (s + e) / 2;
    update(idx, node * 2, s, mid);
    update(idx, node * 2 + 1, mid + 1, e);
}

int query(int idx, int node = 1, int s = 1, int e = S) {
    --tree[node];
    if (s == e) return s;
    int mid = (s + e) / 2;
    if (tree[node * 2] >= idx) return query(idx, node * 2, s, mid);
    else return query(idx - tree[node * 2], node * 2 + 1, mid + 1, e);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0, order, x; i < n; i++) {
        cin >> order >> x;
        if (order == 1) update(x);
        else cout << query(x) << '\n';
    }
    return 0;
}
