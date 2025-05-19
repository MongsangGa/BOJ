#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t, n, m, a, b;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        while (m--)
            cin >> a >> b;
        cout << n - 1 << '\n';
    }
    return 0;
}
