#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define ll long long int

int n, m, order, a, b;
vector<ll> stree;

ll update(int node, int s, int e, int idx, int num) {
    if (idx < s || idx > e) return stree[node];
    if (s == e) return stree[node] = num;
    int mid = (s + e) / 2;
    return stree[node] = update(node * 2, s, mid, idx, num) + update(node * 2 + 1, mid + 1, e, idx, num);
}

ll sum(int node, int s, int e, int findS, int findE) {
    if (s > findE || e < findS) return 0;
    if (s >= findS && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    return sum(node * 2, s, mid, findS, findE) + sum(node * 2 + 1, mid + 1, e, findS, findE);
}

int main() {
    fastio
    cin >> n >> m;
    stree.resize(n * 4);
    while (m--) {
        cin >> order >> a >> b;
        if (!order) {
            if (a > b) swap(a, b);
            cout << sum(1, 1, n, a, b) << '\n';
        } else update(1, 1, n, a, b);
    }
    return 0;
}

