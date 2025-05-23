#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 22
int n, a[S], res[S];

void DFS(int idx, int prev) {
    if (idx == 6) {
        for (int i = 0; i < 6; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = prev; i < n; i++) {
        res[idx] = a[i];
        DFS(idx + 1, i + 1);
    }
}

int main() {
    fastio;
    while (1) {
        cin >> n;
        if (!n) break;
        fill(a, a + S, 0), fill(res, res + S, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        DFS(0, 0);
        cout << '\n';
    }
    return 0;
}
