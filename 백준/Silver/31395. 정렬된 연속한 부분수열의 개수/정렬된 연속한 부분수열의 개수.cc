#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, a, pre = -1, cnt;
long long res;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (pre < a) cnt++;
        else cnt = 1;
        res += cnt, pre = a;
    }
    cout << res;
    return 0;
}
