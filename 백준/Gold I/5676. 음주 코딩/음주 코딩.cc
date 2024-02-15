#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define ll long long int
#define SIZE (int)1e6+1

ll n, m, a, b, stree[SIZE * 4];
char order;

ll update(int node, int s, int e, int idx, int cNum) {
    if (idx < s || idx > e) return stree[node];
    if (s == e) return stree[node] = cNum;
    int mid = (s + e) / 2;
    return stree[node] = update(node * 2, s, mid, idx, cNum) * update(node * 2 + 1, mid + 1, e, idx, cNum);
}

ll query(int node, int s, int e, int findS, int findE) {
    if (s > findE || e < findS) return 1;
    if (s >= findS && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, findS, findE) * query(node * 2 + 1, mid + 1, e, findS, findE);
}

int main() {
    fastio
    while (cin >> n >> m) {
        string res;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a > 0) update(1, 1, n, i, 1);
            else if (a < 0) update(1, 1, n, i, -1);
            else update(1, 1, n, i, 0);
        }
        for (int i = 1; i <= m; i++) {
            cin >> order >> a >> b;
            if (order == 'C') {
                if (b > 0) update(1, 1, n, a, 1);
                else if (b < 0) update(1, 1, n, a, -1);
                else update(1, 1, n, a, 0);
            } else {
                ll t = query(1, 1, n, a, b);
                if (t > 0) cout << "+";
                else if (t < 0) cout << "-";
                else cout << "0";
            }
        }
        cout << '\n';
    }
    return 0;
}
