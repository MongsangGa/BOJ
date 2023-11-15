#include<bits/stdc++.h>

using namespace std;

int n, k, now;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        if (i <= n - k) cout << 'a';
        else cout << char('a' + ++now);
    }
    return 0;
}
