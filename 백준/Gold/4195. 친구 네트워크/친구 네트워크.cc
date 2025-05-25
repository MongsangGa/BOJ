#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 200'002

int t, n, p[S], res[S];
string s1, s2;
map<string, int> m;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    p[v] = u;
    res[u] += res[v], res[v] = 0;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        // init0
        for (int i = 0; i < S; i++)
            p[i] = i, res[i] = 1;
        m.clear();
        int idx = 0;
        // init1
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if (!m[s1]) m[s1] = ++idx;
            if (!m[s2]) m[s2] = ++idx;
            merge(m[s1], m[s2]);
            cout << max(res[find(m[s1])], res[find(m[s2])]) << '\n';
        }
    }
    return 0;
}
