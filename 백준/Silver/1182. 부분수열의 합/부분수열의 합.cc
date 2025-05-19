#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, s, a[22], res;

void DFS(int idx, int sum) {
    if (idx == n) {
        if (sum == s) ++res;
        return;
    }
    DFS(idx + 1, sum);
    DFS(idx + 1, sum + a[idx]);
}

int main() {
    fastio;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    DFS(0, 0);
    if (!s) --res;
    cout << res;
    return 0;
}
