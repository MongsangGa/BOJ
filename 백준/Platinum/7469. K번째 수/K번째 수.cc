#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
const int SIZE = 1e6;

int n, m, a, b, c;
vector<int> stree[SIZE * 4];

void update(int idx, int x, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e)return;
    stree[node].push_back(x);
    if (s != e) {
        int mid = (s + e) / 2;
        update(idx, x, node * 2, s, mid);
        update(idx, x, node * 2 + 1, mid + 1, e);
    }
}

int query(int node, int s, int e, int fS, int fE, int x) {
    if (s > fE || e < fS) return 0;
    if (s >= fS && e <= fE) return upper_bound(stree[node].begin(), stree[node].end(), x) - stree[node].begin();
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, fS, fE, x) + query(node * 2 + 1, mid + 1, e, fS, fE, x);
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        update(i, a);
    }
    for (int i = 0; i <= SIZE * 2; i++) sort(stree[i].begin(), stree[i].end());
    while (m--) {
        cin >> a >> b >> c;
        int l = -1e9, r = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(1, 1, n, a, b, mid) < c) l = mid + 1;
            else r = mid - 1;
        }
        cout << l << '\n';
    }
    return 0;
}
