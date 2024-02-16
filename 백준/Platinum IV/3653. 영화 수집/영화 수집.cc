#include <bits/stdc++.h>

using namespace std;
#define SIZE 200'002
#define fastio cin.tie(0) -> sync_with_stdio(0);

int t, n, m, a, stree[SIZE * 4], arr[SIZE];

void update(int idx, int diff, int node = 1, int s = 0, int e = SIZE) {
    if (idx < s || idx > e) return;
    stree[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(idx, diff, node * 2, s, mid);
    update(idx, diff, node * 2 + 1, mid + 1, e);
}

int query(int findS, int findE, int node = 1, int s = 0, int e = SIZE) {
    if (s > findE || e < findS) return 0;
    if (s >= findS && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    return query(findS, findE, node * 2, s, mid) + query(findS, findE, node * 2 + 1, mid + 1, e);
}

int main() {
    fastio
    cin >> t;
    while (t--) {
        memset(stree, 0, sizeof(stree));
        cin >> n >> m;
        int maxL = n + 1;
        for (int i = 1; i <= n; i++) {
            update(i, 1);
            arr[i] = n - i + 1;
        }
        for (int i = 1; i <= m; i++) {
            cin >> a;
            int &idx = arr[a];
            update(idx, -1);
            cout << query(idx, maxL++) << ' ';
            update(maxL, 1);
            idx = maxL;
        }
        cout << '\n';
    }
    return 0;
}
