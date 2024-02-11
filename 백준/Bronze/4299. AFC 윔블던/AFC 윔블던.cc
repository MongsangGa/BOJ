#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n;

int main() {
    fastio
    int a, b, c = -1, d = -1;
    cin >> a >> b;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (i + j == a && i - j == b) {
                if (i >= j) {
                    c = i;
                    d = j;
                } else {
                    c = j;
                    d = i;
                }
            }
        }
    }
    if (c == -1) cout << -1;
    else cout << c << ' ' << d;
    return 0;
}
