#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define ll long long int
#define SIZE 1'000'001

ll n, m, k, a, b, c, arr[SIZE], stree[SIZE * 4];

ll init(int node, int st, int en) {
    if (st == en) return stree[node] = arr[st];
    int mid = (st + en) / 2;
    return stree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, en);
}

ll update(int node, int st, int en, int idx, ll changeNum) {
    if (idx < st || idx > en) return stree[node];
    if (st == en) return stree[node] = changeNum;
    int mid = (st + en) / 2;
    return stree[node] = update(node * 2, st, mid, idx, changeNum) + update(node * 2 + 1, mid + 1, en, idx, changeNum);
}

ll sum(int node, int st, int en, int x, int y) {
    if (x > en || y < st) return 0;
    if (x <= st && en <= y) return stree[node];
    int mid = (st + en) / 2;
    return sum(node * 2, st, mid, x, y) + sum(node * 2 + 1, mid + 1, en, x, y);
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a & 1) update(1, 1, n, b, c);
        else cout << sum(1, 1, n, b, c) << '\n';
    }
    return 0;
}
