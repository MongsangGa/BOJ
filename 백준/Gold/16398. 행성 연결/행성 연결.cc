#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long int
const int SIZE = 1'001;

int n, cost, p[SIZE], cnt;
ll res;
vector<tuple<int, int, int>> adj;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    p[v] = u;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost;
            if (i == j) continue;
            adj.push_back({cost, i, j});
        }
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(adj.begin(), adj.end());
    for (auto [cost, a, b]: adj) {
        a = find(a), b = find(b);
        if (a == b) continue;
        merge(a, b);
        res += cost, cnt++;
        if (cnt == n) break;
    }
    cout << res;
    return 0;
}
