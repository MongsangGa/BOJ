#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

long long a, b;

int main() {
    fastio;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (b - a <= 1) cout << 0;
    else {
        cout << b - a - 1 << '\n';
        for (long long i = a + 1; i < b; i++) cout << i << ' ';
    }
    return 0;
}
