#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, a[10], v[10];

void DFS(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        a[idx] = i, v[i] = 1;
        DFS(idx + 1);
        v[i] = 0;
    }
}

int main() {
    fastio;
    cin >> n >> m;
    DFS(0);
    return 0;
}
