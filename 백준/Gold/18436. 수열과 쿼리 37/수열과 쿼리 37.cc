#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 100'002
#define pii pair<int,int>

int n, m;
pii stree[SIZE * 4]; // odd, even

pii operator+(const pii &a, const pii &b) {
    pii c;
    c.first = a.first + b.first;
    c.second = a.second + b.second;
    return c;
}

void update(int idx, int diffx, int diffy, int node = 1, int s = 1, int e = n) {
    if (idx > e || idx < s) return;
    if (s == e) {
        stree[node] = {diffx, diffy};
        return;
    }
    int mid = (s + e) / 2;
    update(idx, diffx, diffy, node * 2, s, mid);
    update(idx, diffx, diffy, node * 2 + 1, mid + 1, e);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

pii query(int fS, int fE, int node = 1, int s = 1, int e = n) {
    if (s > fE || e < fS) return {0, 0};
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return query(fS, fE, node * 2, s, mid) + query(fS, fE, node * 2 + 1, mid + 1, e);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        update(i, a % 2, !(a % 2));
    }
    cin >> m;
    while (m--) {
        int order, a, b;
        cin >> order >> a >> b;
        if (order == 1) update(a, b % 2, !(b % 2));
        else if (order == 2) cout << query(a, b).second << '\n';
        else cout << query(a, b).first << '\n';
    }
    return 0;
}
