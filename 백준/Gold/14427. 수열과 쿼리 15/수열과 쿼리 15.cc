#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
const int SIZE = 100'001;
const int INF = 1e9 + 1;
struct node {
    int idx = INF;
    int num = INF;
};
int n, m, order, a, b;
node stree[SIZE * 4];

bool operator<(const node &a, const node &b) {
    if (a.num == b.num) return a.idx < b.idx;
    return a.num < b.num;
}

void update(int idx, int num, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e) return;
    if (s == e) {
        stree[node] = {idx, num};
        return;
    }
    int mid = (s + e) / 2;
    update(idx, num, node * 2, s, mid);
    update(idx, num, node * 2 + 1, mid + 1, e);
    stree[node] = min(stree[node * 2], stree[node * 2 + 1]);
}

node query(int node = 1, int s = 1, int e = n, int fS = 1, int fE = n) {
    if (s > fE || e < fS) return {INF, INF};
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return min(query(node * 2, s, mid, fS, fE), query(node * 2 + 1, mid + 1, e, fS, fE));
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        update(i, a);
    }
    cin >> m;
    while (m--) {
        cin >> order;
        if (order == 2) cout << query().idx << '\n';
        else cin >> a >> b, update(a, b);
    }
    return 0;
}
