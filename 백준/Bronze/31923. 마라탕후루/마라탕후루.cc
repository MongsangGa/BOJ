#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, p, q, diff, a[SIZE], b[SIZE], d[SIZE];
vector<int> res;

int main() {
    fastio;
    cin >> n >> p >> q;
    diff = q - p;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) d[i] = a[i] - b[i];
    for (int i = 0; i < n; i++) {
        if (!diff) { if (a[i] == b[i]) res.push_back(0); }
        else if (!d[i]) res.push_back(0);
        else if (!(d[i] % diff) && d[i] / diff > 0) res.push_back(d[i] / diff);
    }
    if (res.size() != n) cout << "NO";
    else {
        cout << "YES\n";
        for (auto r: res) cout << r << ' ';
    }
    return 0;
}
