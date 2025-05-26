#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, arr[10], vis[10];

void DFS(int idx) {
    if (idx > m) {
        for (int i = 1; i <= m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[idx - 1] > i) continue;
        arr[idx] = i;
        DFS(idx + 1);
    }
}

int main() {
    fastio;
    cin >> n >> m;
    DFS(1);
    return 0;
}
