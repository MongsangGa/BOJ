#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, m;

int main() {
    fastio;
    cin >> n >> m;
    if (n == 1) cout << 1;
    else if (n == 2) cout << min(4, (m + 1) / 2);
    else {
        if (m <= 6) cout << min(4, m);
        else cout << m - 2;
    }
    return 0;
}
