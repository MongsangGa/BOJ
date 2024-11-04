#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, now, cnt;

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        now = now + a > 0 ? now + a : 0;
        if (now >= k) ++cnt;
    }
    cout << cnt;
    return 0;
}
