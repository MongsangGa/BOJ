#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, arr[6], t, p, tCnt;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < 6; i++) cin >> arr[i];
    cin >> t >> p;
    for (int i = 0; i < 6; i++) {
        tCnt += arr[i] / t + 1;
        if (!(arr[i] % t)) --tCnt;
    }
    cout << tCnt << '\n' << n / p << ' ' << n % p;
    return 0;
}

