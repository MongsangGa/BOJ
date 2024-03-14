#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 100'003
int n, m;
vector<int> stree[SIZE * 4];

void update(int idx, int v, int node = 1, int s = 1, int e = n) {
    if (idx > e || idx < s) return;
    stree[node].push_back(v);
    int mid = (s + e) / 2;
    if (s != e) {
        update(idx, v, node * 2, s, mid);
        update(idx, v, node * 2 + 1, mid + 1, e);
    }
}

int query(int fS, int fE, int k, int node = 1, int s = 1, int e = n) {
    if (s > fE || e < fS) return 0;
    if (s >= fS && e <= fE) return stree[node].end() - upper_bound(stree[node].begin(), stree[node].end(), k);
    else {
        int mid = (s + e) / 2;
        return query(fS, fE, k, node * 2, s, mid) + query(fS, fE, k, node * 2 + 1, mid + 1, e);
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        update(i, a);
    }
    for (int i = 1; i < SIZE * 4; i++) sort(stree[i].begin(), stree[i].end());
    cin >> m;
    while (m--) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << query(a, b, k) << '\n';
    }
    return 0;
}
