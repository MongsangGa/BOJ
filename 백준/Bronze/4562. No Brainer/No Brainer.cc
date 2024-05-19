#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a >= b) cout << "MMM BRAINS\n";
        else cout << "NO BRAINS\n";
    }
    return 0;
}
