#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'000'001
#define ll long long int

ll n, m, stree[SIZE * 4];

void update(int idx, int diff, int node = 1, int s = 1, int e = n) {
    if (idx > e || idx < s) return;
    if (s == e) {
        stree[node] += diff;
        return;
    }
    int mid = (s + e) / 2;
    update(idx, diff, node * 2, s, mid);
    update(idx, diff, node * 2 + 1, mid + 1, e);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

ll query(int fS, int fE, int node = 1, int s = 1, int e = n) {
    if (s > fE || e < fS) return 0;
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return query(fS, fE, node * 2, s, mid) + query(fS, fE, node * 2 + 1, mid + 1, e);
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int order, a, b;
        cin >> order >> a >> b;
        if (order == 1) update(a, b);
        else cout << query(a, b) << '\n';
    }
    return 0;
}
