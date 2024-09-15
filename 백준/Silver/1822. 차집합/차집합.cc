#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 500'005

int n, m, a[SIZE], b[SIZE];
vector<int> res;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    for (int i = 0; i < n; i++) {
        if (binary_search(b, b + m, a[i])) continue;
        res.push_back(a[i]);
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto r: res) cout << r << ' ';
    return 0;
}