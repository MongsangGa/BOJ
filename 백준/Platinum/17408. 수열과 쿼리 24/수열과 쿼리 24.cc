#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define pii pair<int,int>
#define S 100'001

int n, m, arr[S];
pii tree[S * 4];

pii f(pii a, pii b) {
    vector<int> v = {a.first, a.second, b.first, b.second};
    sort(v.rbegin(), v.rend());
    return {v[0], v[1]};
}

void update(int idx, int x, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[node].first = x;
        return;
    }
    int mid = (s + e) / 2;
    update(idx, x, node * 2, s, mid);
    update(idx, x, node * 2 + 1, mid + 1, e);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

pair<int, int> query(int qs, int qe, int node = 1, int s = 1, int e = n) {
    if (qs > e || qe < s) return {0, 0};
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return f(query(qs, qe, node * 2, s, mid), query(qs, qe, node * 2 + 1, mid + 1, e));
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        update(i, x);
    }
    cin >> m;
    while (m--) {
        int order, a, b;
        cin >> order >> a >> b;
        if (order == 1) update(a, b);
        else {
            pair<int, int> res = query(a, b);
            cout << res.first + res.second << '\n';
        }
    }
    return 0;
}
