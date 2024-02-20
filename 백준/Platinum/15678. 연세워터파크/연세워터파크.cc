#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long int
#define SIZE ((int)1e5+1)
#define INF 1e9+1

int n, d;
ll dp[SIZE], stree[SIZE * 4];

ll query(int node, int s, int e, int fS, int fE) {
    if (s > fE || e < fS) return -INF;
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return max(query(node * 2, s, mid, fS, fE), query(node * 2 + 1, mid + 1, e, fS, fE));
}

void update(int node, int s, int e, int idx, ll k) {
    if (idx > e || idx < s) return;
    if (s == e) {
        stree[node] = k;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, k);
    update(node * 2 + 1, mid + 1, e, idx, k);
    stree[node] = max(stree[node * 2], stree[node * 2 + 1]);
}

int main() {
    fastio;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> dp[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i] + query(1, 1, n, max(0, i - d), i - 1));
        update(1, 1, n, i, dp[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}
