#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

inline int p(int x) { return x * x; }

int main() {
    fastio;
    int t, x1, y1, r1, x2, y2, r2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = p(x1 - x2) + p(y1 - y2);
        if (!dist && r1 == r2) cout << "-1\n";
        else if (dist > p(r1 + r2)) cout << "0\n";
        else if (dist == p(r1 + r2)) cout << "1\n";
        else if (dist < p(r1 + r2)) {
            if (dist > p(r1 - r2)) cout << "2\n";
            else if (dist == p(r1 - r2)) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}
