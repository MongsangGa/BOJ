#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t = 1, n, j, two, five;

int main() {
    fastio;
    while (t++) {
        cin >> n;
        if (!n) break;
        two = five = 0;
        for (int i = 2; i <= n; i++) {
            j = i;
            while (!(j % 2)) j /= 2, ++two;
            j = i;
            while (!(j % 5)) j /= 5, ++five;
        }
        cout << "Case #" << t - 1 << ": " << min(two, five) << '\n';
    }
    return 0;
}
