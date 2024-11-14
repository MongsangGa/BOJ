#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, x, y, b;

int main() {
    fastio;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    cin >> x >> y;
    double a = (double) n * ((double) x / 100);
    for (auto i: v) if (i >= y) ++b;
    cout << a << ' ' << b;
    return 0;
}
