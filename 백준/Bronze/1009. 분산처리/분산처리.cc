#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t, a, b;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int res = 1;
        for (int i = 0; i < b; i++)
            res *= a, res %= 10;
        if (!res) cout << "10\n";
        else cout << res << '\n';
    }
    return 0;
}
