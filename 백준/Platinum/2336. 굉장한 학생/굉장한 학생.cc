#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 500'002
#define INF 1e9
struct score {
    int x, y, z;
};

bool cmp(const score &a, const score &b) {
    return a.x < b.x;
}

score v[SIZE];
int n, a, res, stree[4 * SIZE];

int query(int fS, int fE, int node = 1, int s = 1, int e = n) {
    if (s > fE || e < fS) return INF;
    if (fS <= s && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return min(query(fS, fE, node * 2, s, mid), query(fS, fE, node * 2 + 1, mid + 1, e));
}

int update(int idx, int c, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e) return stree[node];
    if (s == e) return stree[node] = c;
    int mid = (s + e) / 2;
    return stree[node] = min(update(idx, c, node * 2, s, mid), update(idx, c, node * 2 + 1, mid + 1, e));
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a, v[a].x = i;
    for (int i = 1; i <= n; i++) cin >> a, v[a].y = i;
    for (int i = 1; i <= n; i++) cin >> a, v[a].z = i;
    sort(v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; i++) update(i, INF);
    for (int i = 1; i <= n; i++) {
        if (query(1, v[i].y) > v[i].z) res++;
        update(v[i].y, v[i].z);
    }
    cout << res;
    return 0;
}
