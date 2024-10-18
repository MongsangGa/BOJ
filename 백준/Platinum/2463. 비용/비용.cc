#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long int
#define SIZE 100'002
#define MOD (ll)1e9

struct INFO {
    int u, v, c;
};
int n, m, p[SIZE], cnt[SIZE];
ll res, sum;
INFO arr[SIZE];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (cnt[u] > cnt[v]) {
        p[v] = u;
        cnt[u] += cnt[v];
    } else if (cnt[u] <= cnt[v]) {
        p[u] = v;
        cnt[v] += cnt[u];
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].u >> arr[i].v >> arr[i].c;
        sum += arr[i].c;
    }
    sort(arr, arr + m, [&](INFO &a, INFO &b) {
        return a.c > b.c;
    });
    for (int i = 1; i <= n; i++)
        p[i] = i, cnt[i] = 1;
    for (int i = 0; i < m; i++) {
        auto now = arr[i];
        int uu = find(now.u), vv = find(now.v);
        if (uu != vv) {
            res += ((ll) cnt[uu] * cnt[vv] * sum) % MOD;
            merge(now.u, now.v);
        }
        sum -= now.c;
    }
    cout << res % MOD;
    return 0;
}
