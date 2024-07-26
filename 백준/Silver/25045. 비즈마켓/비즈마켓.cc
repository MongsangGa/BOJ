#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
int n, m;
ll res;
vector<int> a, b;

int main() {
    fastio;
    cin >> n >> m;
    a.resize(n), b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end(), greater<int>()), sort(b.begin(), b.end());
    for (int i = 0; i < n && i < m; i++) {
        if (a[i] - b[i] < 0) continue;
        res += a[i] - b[i];
    }
    cout << res;
    return 0;
}
