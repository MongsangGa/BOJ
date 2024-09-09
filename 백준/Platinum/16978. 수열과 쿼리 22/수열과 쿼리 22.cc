#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define SIZE 100'003

struct A {
    int i, v;
};

struct B {
    int k, i, j, idx;
};

int n, m;
ll stree[SIZE * 4], res[SIZE];
vector<A> a;
vector<B> b;

void update(int node, int s, int e, int idx, int diff) {
    if (idx < s || idx > e) return;
    stree[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, diff);
    update(node * 2 + 1, mid + 1, e, idx, diff);
}

ll query(int node, int s, int e, int qs, int qe) {
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return stree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, qs, qe) + query(node * 2 + 1, mid + 1, e, qs, qe);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    cin >> m;
    int bidx = 0;
    while (m--) {
        int order;
        cin >> order;
        if (order == 1) {
            int i, v;
            cin >> i >> v;
            a.push_back({i, v});
        } else {
            int k, i, j;
            cin >> k >> i >> j;
            b.push_back({k, i, j, bidx++});
        }
    }
    sort(b.begin(), b.end(), [](B &x, B &y) {
        return x.k < y.k;
    });
    bidx = 0;
    for (int i = 0; i < a.size(); i++) {
        while (b[bidx].k == i) {
            auto now = b[bidx];
            res[now.idx] = query(1, 1, n, now.i, now.j);
            ++bidx;
        }
        auto now = a[i];
        int diff = query(1, 1, n, now.i, now.i);
        update(1, 1, n, now.i, now.v - diff);
    }
    for (int i = bidx; i < b.size(); i++)
        res[b[i].idx] = query(1, 1, n, b[i].i, b[i].j);
    for (int i = 0; i < b.size(); i++)
        cout << res[i] << '\n';
    return 0;
}
