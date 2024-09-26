#include <bits/stdc++.h>

using namespace std;
#define SIZE 10'002

int n, m, k, arr[SIZE], p[SIZE], res;
unordered_set<int> s;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (arr[u] < arr[v]) p[v] = u;
    else p[u] = v;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
        s.insert(find(i));
    for (auto i: s)
        res += arr[i];
    if (res > k) cout << "Oh no";
    else cout << res;
    return 0;
}
