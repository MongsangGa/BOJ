#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int n, res;

int main() {
    fastio;
    cin >> n;
    while (n > 0) {
        if (!(n % 5))
            res += (n / 5), n = 0;
        else n -= 2, res++;
    }
    if (n < 0) cout << -1;
    else cout << res;
    return 0;
}
