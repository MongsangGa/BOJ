#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 100'009

int n, m, a, b, c;
vector<int> stree[SIZE * 4];

void update(int idx, int x, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e) return;
    stree[node].push_back(x);
    if (s ^ e) {
        int mid = (s + e) / 2;
        update(idx, x, node * 2, s, mid);
        update(idx, x, node * 2 + 1, mid + 1, e);
    }
}

int query(int fS, int fE, int x, int node = 1, int s = 1, int e = n) {
    if (s > fE || e < fS) return 0;
    if (fS <= s && e <= fE)
        return stree[node].end() - upper_bound(stree[node].begin(), stree[node].end(), x);
    int mid = (s + e) / 2;
    return query(fS, fE, x, node * 2, s, mid) + query(fS, fE, x, node * 2 + 1, mid + 1, e);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a, update(i, a);
    cin >> m;
    for (int i = 0; i < SIZE * 4; i++)
        sort(stree[i].begin(), stree[i].end());
    int ans = 0;
    while (m--) {
        cin >> a >> b >> c;
        a ^= ans, b ^= ans, c ^= ans;
        ans = query(a, b, c);
        cout << ans << '\n';
    }
    return 0;
}
