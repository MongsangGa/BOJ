#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, a, b, m, v[21];

int DFS(int s, int e, int cur) {
    if (cur == m) return 0;
    int res = 1e9;
    if (v[cur] == s || v[cur] == e) res = min(res, DFS(s, e, cur + 1));
    if (v[cur] < s) res = min(res, DFS(v[cur], e, cur + 1) + s - v[cur]);
    if (v[cur] > e) res = min(res, DFS(s, v[cur], cur + 1) + v[cur] - e);
    if (s < v[cur] && v[cur] < e)
        res = min({res, DFS(v[cur], e, cur + 1) + v[cur] - s, DFS(s, v[cur], cur + 1) + e - v[cur]});
    return res;
}

int main() {
    fastio;
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) cin >> v[i];
    if (a > b) swap(a, b);
    cout << DFS(a, b, 0);
    return 0;
}
