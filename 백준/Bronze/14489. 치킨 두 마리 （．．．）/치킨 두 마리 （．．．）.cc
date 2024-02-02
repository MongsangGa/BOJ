#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int a, b, c;

int main() {
    fastio;
    cin >> a >> b >> c;
    if (a + b >= c * 2) cout << a + b - c * 2;
    else cout << a + b;
    return 0;
}
